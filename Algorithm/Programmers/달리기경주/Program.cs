// See https://aka.ms/new-console-template for more information
using System;
using System.Collections;
using System.Collections.Specialized;
public class Solution {
    public string[] solution(string[] players, string[] callings) {
        string[] answer = new string[] {};
        int callingLength = callings.Length;
        int playerLength= players.Length;
            
        Dictionary<string,int> dic = new  Dictionary<string,int>();

        for(int i=0;i<playerLength;i++)
        {
            dic.Add(players[i],i);
        }

        for(int i=0;i<callingLength;i++)
        {
            string SrcString;
            int FoundIndex;

            SrcString = callings[i];
            FoundIndex = dic[SrcString];
            dic[SrcString]--;
            dic[players[FoundIndex-1]]++;

            swap(players,FoundIndex,FoundIndex -1);

        }
        return players;
    }

    private void swap(string[] array, int SrcIdx, int DstIdx)
    {
        string DstString = array[SrcIdx];
        array[SrcIdx] = array[DstIdx];
        array[DstIdx] = DstString;
    }
}