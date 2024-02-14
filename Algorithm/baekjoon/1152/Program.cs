public class Solution
{
    public static void Main(string[] args)
    {
        Solution1();
    }

    public static void Solution1()
    {
        StreamReader sr = new(new BufferedStream(Console.OpenStandardInput()));
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
        int start = 0;
        int end = 0;
        int answer = 0;
        string str = sr.ReadLine().Trim();
        end = str.Length-1;
        bool charStart = false;
        for(int i= start;i<=end;++i)
        {
            if(!charStart && str[i] != ' ')
            {
                answer++;
                charStart= true;
            }else if(charStart && str[i] == ' ')
            {
                charStart = false;
            }
        }
        
        sw.WriteLine(answer);
        sr.Close();
        sw.Close(); 
    }
}