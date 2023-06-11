using UnityEngine;

/// <summary>
/// Save가 필요한 오브젝트라면 무조건 상속해야하는 클래스, SaveNLoadManager는 SaveUnit을 통해 데이터를 가져오고 넣고함.
/// SaveNLoadManager에 자동으로 등록되고 해제되고 할 수 있도록 만듬, 
/// 또한 SaveNLoadManager를 통해 하는 Game시작과 끝때에 오브젝트의 움직임 활성화와 관련된 내용을 담고 있다.
/// </summary>

public abstract class SaveUnit : MonoBehaviour, IControlUnit
{
    // Activated 즉 게임에서 이 오브젝트가 동작 중인지 체크해주는 변수
    // 이 변수는 각 오브젝트에서 현재 동작해도 되는지를 체크하는 변수로 사용
    private bool isActive = false;

    // 이 오브젝트가 로드된 오브젝트인지 체크,
    // 처음 동작할때와, 로드되서 동작하는데에 차이가 있기 때문에 체크하기 위한용도
    // SetData(로드하는 과정)를 하게되면 true로 바뀐다.
    // DeActivate시 자동으로 false화 시킴
    private bool isLoadedObject = false;

    // isRegisteredToSaveNLoadManager는 SaveNLoadManager상에 등록이 되어있는지의 여부를 체크해준다.
    // 중복 저장되는것을 방지하기 위함( Start(), OnEnable() 실행으로 )
    // OnEnable만 사용하면 되는거 아니냐?
    // -> 처음 시작시 OnEnable이 작동이 제대로 안되는것으로 보임... 그래서 등록이 안되어 따로따로 추가했고, 중복 방지한것임
    // 게임시작시 OnEnable() -> Start()순으로 실행이 된다. 유니티 이벤트 함수 루틴 참고
    private bool isRegisteredToSaveNLoadManager = false;

    protected virtual void Start()
    {
        if (SaveNLoadManager.Instance && !isRegisteredToSaveNLoadManager)
        {
            SaveNLoadManager.Instance.RegistSaveUnit(this);
            isRegisteredToSaveNLoadManager = true;
        }
    }
    // 오브젝트 활성화시 자동으로 실행되는 메소드
    protected void OnEnable()
    {
        if (SaveNLoadManager.Instance && !isRegisteredToSaveNLoadManager)
        {
            SaveNLoadManager.Instance.RegistSaveUnit(this);
            isRegisteredToSaveNLoadManager = true;
        }
    }
    // 오브젝트 비활성화시 자동으로 실행되는 메소드
    protected void OnDisable()
    {
        if (SaveNLoadManager.Instance)
        {
            SaveNLoadManager.Instance.RemoveSaveUnit(this);
            isRegisteredToSaveNLoadManager = false;
        }
    }
    /// <summary>
    /// JsonUtility를 이용하여 데이터를 반환하시면 됩니다.
    /// </summary>
    /// <param name="objectName"></param>
    /// <returns></returns>
    public abstract object GetSavingData(out string objectName);
    /// <summary>
    /// JsonUtility를 통해 데이터를 얻어 초기화값을 설정하시면 됩니다.
    /// </summary>
    /// <param name="savedData"></param>
    public virtual void SetSaveData(string savedData) {
        isLoadedObject = true;
    }
    public virtual void Activate()
    {
        isActive = true;
    }
    public virtual void DeActivate()
    {
        isActive = false;
        isLoadedObject = false;
    }
    public bool IsActivated()
    {
        return isActive;
    }
    public bool isLoaded()
    {
        return isLoadedObject;
    }
}