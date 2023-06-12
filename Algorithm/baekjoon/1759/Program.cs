using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
public class Solution
{
    StreamReader sr = new(new BufferedStream(Console.OpenStandardInput()));        
    StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
    public List<char> check = new List<char>();
    public char[] alpha;
    int cLength = 0;
    public static void Main(string[] args)
    {
        Solution sol = new Solution();
        sol.solve();
    }
    public void solve()
    {
        cLength = int.Parse(sr.ReadLine().Split()[0]);

        alpha = (from x in sr.ReadLine().ToCharArray()
                        where x != ' '
                        select x).ToArray();
       
        Array.Sort(alpha);

        for(int i=0;i<alpha.Length;i++)
        {
            check.Add(alpha[i]); 
            solve(i);
            check.RemoveAt(check.Count-1);
        }
        sr.Close();
        sw.Close();
    }
    public void solve(int i)
    {
        if(check.Count > cLength)
            return;
        if(check.Count>=cLength)
        {
            string content = new(check.ToArray<char>());
            int count = content.Where((x) => "aeiou".Any(y => x == y)).Count();
            if(count >= 1 && check.Count()-count >= 2)
            {
                sw.WriteLine(content);
                return;
            }
        }
            
        for(int j=i+1; j<alpha.Length;j++)
        {
            check.Add(alpha[j]); 
            solve(j);
            check.RemoveAt(check.Count-1);
        }
    }
}

// 문제의 조건을 정확하게 맞춰주자
// 처음에 하나만 맞춰서 망했는데
// 모음만 있는경우도 존재하니까...
// 항상 조건을 걍 똑같이 맞춰줄것. -> 조건으로 다 틀렷네
// 1. 자음 2개 이상인거 무시
// 2. 재귀돌면서 자동으로 4개 이상도 될 수 있는 상황인데, 그걸 예상하지 못함.
// 3. 그냥 딱 들어맞는 조건으로 수행하는게 더 이득인듯.