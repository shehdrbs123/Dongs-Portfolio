public class Solution
{
    public static void Main(string[] args)
    {
        StreamReader sr = new(new BufferedStream(Console.OpenStandardInput()));
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
        
        string str = sr.ReadLine();
        int target = int.Parse(str);
        
        int data = target / 5;
        int i= data;
        for(;i>=0;--i)
        {
            int rest = target -(5 *i);
            int threeRest = rest % 3;
            if(rest == 0)
            {
                sw.WriteLine(i);
                break;
            }
            if(threeRest == 0)
            {
                sw.WriteLine(rest/3 + i);
                break;
            }
        }
        if(i == -1)
            sw.WriteLine(i);
        sr.Close();
        sw.Close();
    }
}