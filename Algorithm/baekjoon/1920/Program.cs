using System.Text;

// mingu991114님 것을 참조하여 구성해봤음.
// 핵심 쟁점은 빨리 읽게하고, 컨테이너에 빨리 넣게 하고,
// 그 컨테이너에서 빠르게 뽑을 수 있어야된다.
// 입력과 출력을 보면서 문제를 읽자
// 이번엔 나름의 이진탐색으로 해봄.. 소팅 과정이 잇어야되서, 이게 가능할랑가는 모르겠다.
// 탐색은 보통 속도를 보게 되어있음.

internal class Solution
{
    public static void Main(string[] args)
    {
        StreamReader sr = new(new BufferedStream(Console.OpenStandardInput()));
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
        
        sr.ReadLine();

        string[] stringData = sr.ReadLine().Split(' ');
        var arDataStore = Array.ConvertAll<string,int>(stringData,int.Parse);
        Array.Sort(arDataStore);
        sr.ReadLine();

        var arFindNum = sr.ReadLine().Split(' ');

        foreach(var s in arFindNum)
        {
            int answer = Solution.Solve(s,arDataStore);
            sw.WriteLine(answer);
        }
        
        sr.Close();
        sw.Close();
    }

    private static int Solve(string srNum, int[] arDataStore)
    {
        int start = 0;
        int end = arDataStore.Length - 1;
        int middle = 0;    
        int answer = 0;
        int nNum = int.Parse(srNum);
        while(start <= end && answer == 0)
        {
            middle = (start+ end) / 2;
            int currentValue = arDataStore[middle];
            if(currentValue == nNum)
            {
                answer = 1;
            }
            else if(currentValue > nNum)
            {
                end = middle - 1;
            }
            else
            {
                start = middle + 1;
            }   
        }
        return answer;
    }
}