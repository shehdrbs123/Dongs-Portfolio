using System.Collections.Generic;
using UnityEngine;
using System;
using System.IO;
using System.Text;

/// <summary>
/// 세이브와 로드를 담당하는 클래스
/// 세이브/로드와는 별개로, 로드된 오브젝트의 움직임을 시작할때 필요한 클래스 이기도 하다.
/// 로드 후 로드가 완료되면 GameManager에서 로드된 오브젝트의 움직임 시작을 명령,
///  => 별개의 컨테이너를 마련해서 거기서 수행할까 싶기도하다.
/// </summary>
public class SaveNLoadManager : MonoBehaviour
{
    public static SaveNLoadManager Instance; // 싱글턴 패턴
    // 필드에 이미 생성되어있는 오브젝트들로, 삭제될 일이 없는 오브젝트들을 저장하는 리스트
    [SerializeField] private List<SaveUnit> staticData;
    // 필드에 없으며, 계속적으로 생성되는 오브젝트들을 저장하는 리스트 (ObjectManager와 연계되어있다)
    [SerializeField] private List<SaveUnit> dynamicData;

    // 저장할 파일 이름
    [SerializeField] private string fileName;
    private string dataPath;
    // 저장을 바로 하는것이 아닌 tmp파일에 저장시킨후, tmp로 기존 파일을 덮어씀
    // 혹시나 모를 파일 쓰는 중에 에러로 파일이 날라가는것을 방지하기 위함
    private string tempPath;

    private StringBuilder sb;

    // 파일 저장시, 이름과 JSON 값을 분리하기 위한 값들
    char nameSpliter = '|';
    char dataSpliter = '\n';
    string staticLineSpliter = " ";
    private void Start()
    {
        if (Instance)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        staticData = new List<SaveUnit>();
        dynamicData = new List<SaveUnit>();
        dataPath = Application.persistentDataPath + "\\" + fileName;
        tempPath = dataPath + ".tmp";
        sb = new StringBuilder();
    }
    //SaveUnit을 상속한 오브젝트가 리스트 등록요청할 때 사용
    public void RegistSaveUnit(SaveUnit unit)
    {
        bool isCompareTag = unit.CompareTag("StaticSave");
        if (isCompareTag)
        {
            staticData.Add(unit);
#if UNITY_EDITOR
            Debug.Log(unit.name + "(StaticData) is Added in SaveNLoadManager");
#endif
        }
        else
        {
            dynamicData.Add(unit);
#if UNITY_EDITOR
            Debug.Log(unit.name + "(DynamicData) is Added in SaveNLoadManager");
#endif
        }
    }
    //SaveUnit을 상속한 오브젝트가 리스트에서의 삭제요청이 필요할 때 사용
    public void RemoveSaveUnit(SaveUnit unit)
    {
        if (unit.CompareTag("StaticSave"))
            staticData.Remove(unit);
        else
            dynamicData.Remove(unit);
#if UNITY_EDITOR
        Debug.Log(unit.name + " is Removed in SaveNLoadManager");
#endif
    }

    //게임을 처음상태부터 시작할 때 사용
    public void New()
    {
        if (File.Exists(dataPath))
        {
#if UNITY_EDITOR
            Debug.Log("경고");
#endif
            File.Delete(dataPath);
        }
    }

    //게임을 저장할때 사용
    // GameManager가 주기적으로 호출하게끔 설계됨 ( 현재는 1초 )
    public async void Save()
    {
        using (StreamWriter sw = File.CreateText(tempPath))
        {
            //정적인 객체들 저장
            for (int i = 0; i < staticData.Count; i++)
                AddSaveDataToStringBuilder(staticData[i]);

            //정적데이터 동적데이터를 나누기 위한 spliter
            sb.Append(staticLineSpliter).Append(dataSpliter);

            //동적인 객체들 저장
            for (int i = 0; i < dynamicData.Count; i++)
               AddSaveDataToStringBuilder(dynamicData[i]);

            byte[] allData = Encoding.Default.GetBytes(sb.ToString());
            
            sb.Clear();
            await sw.WriteAsync(Convert.ToBase64String(allData));
        }

        if (File.Exists(dataPath))
            File.Delete(dataPath);
        File.Move(tempPath, dataPath);

#if UNITY_EDITOR
        Debug.Log("SaveComplete");
#endif
    }
    // 오브젝트를 식별하기 위한 데이터를 추가
    private void AddSaveDataToStringBuilder(SaveUnit unit)
    {
        string uniqueName;
        object data = unit.GetSavingData(out uniqueName);
        sb.Append(uniqueName).Append(nameSpliter).Append(JsonUtility.ToJson(data)).Append(dataSpliter);
    }

    // 데이터를 로드할 때 사용
    public void Load()
    {
        try
        {
            string data;
            using (StreamReader sr = File.OpenText(dataPath))
                data = sr.ReadToEnd();
            if (data == null)
                return;
            data = Encoding.Default.GetString(Convert.FromBase64String(data));
            string[] splitedData = data.Split(dataSpliter);

            GameObject[] staticData = GameObject.FindGameObjectsWithTag("StaticSave");
            int i;
            //정적 객체로드 
            for (i = 0; i < splitedData.Length; i++)
            {
                if (splitedData[i] == staticLineSpliter)
                    break;
                SetStaticData(splitedData[i], staticData);
            }
            i += 1;
            //동적 객체로드
            for (; i < splitedData.Length - 1; i++)
                SetDynimicData(splitedData[i]);
        }
        catch
        {
            DeActivate();
        }
    }
    // ObjectPoolManager에 등록되어 사용되는 오브젝트에 데이터를 설정 때 사용
    // 즉 동적으로 생성이 필요한 오브젝트들에 사용
    private void SetDynimicData(string data)
    {
        string[] sep = data.Split(nameSpliter);
        GameObject go = ObjectPoolManager.Instance.GetGameObject(sep[0]);
        go.GetComponent<SaveUnit>().SetSaveData(sep[1]);
    }

    // StaticSave 태그가 붙은 오브젝트의 데이터를 설정할 때 사용
    private void SetStaticData(string jsonData, GameObject[] staticData)
    {
        string[] sep = jsonData.Split(nameSpliter);
        GameObject go = Array.Find(staticData, x => x.name.CompareTo(sep[0]) == 0);
        go.GetComponent<SaveUnit>().SetSaveData(sep[1]);
    }

    // 저장이 필요한 데이터는 보통 움직임이 발생하거나 생성되는 오브젝트로서
    // 로드 중에 동작을 방지하기 위한 하나의 로직임
    // 로드가 모두 완료됬을 때 동작을 시작하게끔 구성되어있음.
    public void Activate()
    {
        for (int i = 0; i < staticData.Count; i++)
        {
            staticData[i].Activate();
        }
        for (int i = 0; i < dynamicData.Count; i++)
        {
            dynamicData[i].Activate();
        }
    }
    public void DeActivate()
    {
        for (int i = 0; i < staticData.Count; i++)
        {
            staticData[i].DeActivate();
        }
        while (dynamicData.Count >0)
        {
            dynamicData[0].DeActivate();
        }
    }

    // 저장 파일의 삭제가 필요할 때 사용
    public void DeleteSavedFile()
    {
        if (File.Exists(dataPath))
            File.Delete(dataPath);
    }
}