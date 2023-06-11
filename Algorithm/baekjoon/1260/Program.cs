using System;
using System.Collections.Generic;

public class Program
{
    
    public static void Main(string[] args)
    {
        // 입력 세팅
        StreamReader sr = new(new BufferedStream(Console.OpenStandardInput()));
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
        Dictionary<int,SortedSet<int>> edgeDic = new Dictionary<int, SortedSet<int>>();

        int[] input = null;
        int vertexCount = 0;
        int EdgeSize=0;
        int start=0;
        
        // 첫줄 입력 받기
        input = Array.ConvertAll<string,int>(sr.ReadLine().Split(' '),int.Parse);
        vertexCount = input[0];
        EdgeSize = input[1];
        start = input[2];        
        
        // 엣지 입력 받기
        for(int i=0;i<EdgeSize;i++)
        {
            input = Array.ConvertAll<string,int>(sr.ReadLine().Split(' '),int.Parse);
            SortedSet<int> edgeList;
            // 양방향으로 갈 수 있으므로 양방향 등록

            if(!edgeDic.TryGetValue(input[0],out edgeList))
            {
                edgeList = new SortedSet<int>();
                edgeDic.Add(input[0],edgeList);
            }
            edgeList.Add(input[1]);

            if(!edgeDic.TryGetValue(input[1],out edgeList))
            {
                edgeList = new SortedSet<int>();
                edgeDic.Add(input[1],edgeList);
            }
            edgeList.Add(input[0]);
        }
        //printDic(edgeDic);
        Program.DFS(edgeDic,start,vertexCount);
        Program.BFS(edgeDic,start,vertexCount);
        //DFS
        
        sr.Close();
        sw.Close();
    }

    private static void printDic(Dictionary<int,SortedSet<int>> edgeDic)
    {
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
        foreach(KeyValuePair<int,SortedSet<int>> a in edgeDic)
        {
            sw.Write("{0} : ",a.Key);
            foreach(int x in a.Value)
            {
                sw.Write("{0} ",x);
            }
            sw.WriteLine();
        }
        sw.Close();
    }

    private static void BFS(Dictionary<int,SortedSet<int>> edgeDic,int start,int vertexCount)
    {
        StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
       
        bool[] visit = new bool[vertexCount];
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(start);
        //queue를 이용한 BFS 수행
        while(queue.Count > 0)
        {
            int num = queue.Dequeue();
            if(!visit[num-1])
            {
                SortedSet<int> list;
                if(edgeDic.TryGetValue(num,out list))
                {
                    foreach(int x in list) 
                        queue.Enqueue(x);
                }
                visit[num-1] = true;
                sw.Write("{0} ",num);
            }
        }
        sw.Close();
    }

    private static void DFS(Dictionary<int,SortedSet<int>> edgeDic,int start,int vertexCount)
    {
       StreamWriter sw = new(new BufferedStream(Console.OpenStandardOutput()));
       
        bool[] visit = new bool[vertexCount];
        Stack<int> stack = new Stack<int>();
        stack.Push(start);
        // stack을 이용한 DFS 수행
        // sortedSet은 오름차순 정렬이므로, stack에 값을 넣을 때 반대로 넣어줘야함
        while(stack.Count > 0)
        {
            int num = stack.Pop();
            if(!visit[num-1])
            {
                SortedSet<int> list;
                if(edgeDic.TryGetValue(num,out list))
                {
                    // 뒤집어서 차례로 넣어주기
                    foreach(int x in list.Reverse()) 
                        stack.Push(x);
                }
                visit[num-1] = true;
                sw.Write("{0} ",num);
            }
        }
        sw.WriteLine();
        sw.Close();
    }
}