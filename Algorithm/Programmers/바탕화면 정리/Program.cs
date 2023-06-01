// See https://aka.ms/new-console-template for more information
using System;
using System.Collections;

public class Solution {
    public static void Main(string[] args)
    {
        string[] wallpaper = {".#...", "..#..", "...#."};
        int[] result = {0, 1, 3, 4};
        int[] answer;
        Solution sol = new Solution();
        answer = sol.solution(wallpaper);

        if(checkEqulity(result,answer))
        {
            Console.WriteLine("통과");
        }
        else
        {
            Console.Write("Result: ");
            Array.ForEach<int>(result, num => Console.Write(num +" "));
            Console.WriteLine();
            Console.Write("Answer: ");
            Array.ForEach<int>(answer, num => Console.Write(num +" "));
            Console.WriteLine("\n실패");
        }
    }
    private static bool checkEqulity(int[] answer, int[] result)
    {
        return Enumerable.SequenceEqual<int>(answer,result);
    }
    public int[] solution(string[] wallpaper) {
        int[] answer = new int[4];
        
        List<Tuple<int,int>> files = new List<Tuple<int, int>>();


        GetFilesPos(wallpaper,files);
        GetDragRange(files,answer);

        return answer;
    }

    private void GetFilesPos(string[] wallpaper,List<Tuple<int,int>> files)
    {
        if(files == null)
            files = new List<Tuple<int, int>>();

        for(int i=0;i<wallpaper.Length;i++)
        {
            string wallpaperRow = wallpaper[i];
            for(int j=0;j<wallpaperRow.Length; j++)
            {
                if(wallpaperRow[j] == '#')
                {
                    files.Add(new Tuple<int, int>(i,j));
                }
            }
        }
        //files.ForEach( x => Console.WriteLine(x.Item1 + " " + x.Item2));
    }

    private void GetDragRange(List<Tuple<int,int>> filesPos,int[] answer)
    {
        int xMax, xMin;
        int yMax, yMin;
        xMin = filesPos[0].Item1;
        xMax = filesPos[0].Item1+1;
        yMin = filesPos[0].Item2;
        yMax = filesPos[0].Item2+1;
        filesPos.RemoveAt(0);

        filesPos.ForEach( (x) => {
            if(x.Item1+1 > xMax)
            {
                xMax = x.Item1+1;
            }
            else if (x.Item1 < xMin)
            {
                xMin = x.Item1;
            }

            if(x.Item2+1 > yMax)
            {
                yMax = x.Item2+1;
            }
            else if(x.Item2 < yMin)
            {
                yMin = x.Item2;
            }
        });

        answer[0] = xMin;
        answer[1] = yMin;
        answer[2] = xMax;
        answer[3] = yMax;   
    }
    
    private void printStrings(string[] array) 
    {
        for(int i=0;i<array.Length;i++)
        {
            Console.WriteLine(array[i]);
        }
    }
}