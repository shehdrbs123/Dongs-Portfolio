public class Solution
{
    public static void Main(string[] args)
    {
        StreamReader sr = new(new BufferedStream(Console.OpenStandardInput()));
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));

        int answer = 0;
        string str = sr.ReadLine();
        string[] split = str.Split();
        
        int large = int.Parse(split[0]);
        int small = int.Parse(split[1]);
        
        answer = large*small -1;
        
        sw.WriteLine(answer);
        sr.Close();
        sw.Close();
    }
}