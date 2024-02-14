// See https://aka.ms/new-console-template for more information


using System;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        int[] answer = new answer[commands.Length/3];

        for(int i=0;i<answer.Length;++i)
        {
            int startIdx = commands[0];
            int endIdx = commands[1];
            int selectIdx = commands[2];

            if(startIdx > endIdx)
            {
                int tmp = startIdx;
                startIdx = endIdx;
                endIdx = tmp;
            }
            int subLength = endIdx - startIdx;
            int[] sub = new int[subLength]; 

            for(int j=0;j<sub.Length;++j)
            {
                sub[j] = array[startIdx];
                ++startIdx;
            }   
            sub.sort();

            answer[j] = sub[selectIdx];
        }
        

        return answer;
    }
}