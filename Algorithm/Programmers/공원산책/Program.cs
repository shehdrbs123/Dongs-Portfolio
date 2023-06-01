// See https://aka.ms/new-console-template for more information

using System;
using System.Linq;
public class Solution {

    public static void Main(string[] args)
    {
        string[] park = {"SOO","OOO","OOO"};
        string[] routes = {"E 2","S 2","W 1"};
        int[] result = {2,1};
        int[] answer;
        Solution sol = new Solution();
        answer = sol.solution(park,routes);

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
    public int[] solution(string[] park, string[] routes) {
        int[] answer = new int[2];       
        char[][] toCharPark;
        int xPos = 0;
        int yPos = 0;

        toCharPark = makeCharArray(park);

        findCurrentPos(toCharPark,out xPos,out yPos);
        answer[0] = yPos;
        answer[1] = xPos;

        
        for(int i=0;i<routes.Length; i++)
        {
            char[] splitData = routes[i].ToCharArray();
            int deltaX=0;
            int deltaY=0;
            switch(splitData[0]) 
            {
                case 'E':
                    deltaX = 1;
                break;
                case 'W':
                    deltaX = -1;
                break;
                case 'S':
                    deltaY = 1;
                break;
                case 'N':
                    deltaY = -1;
                break;
            }
            move(toCharPark,ref xPos,ref yPos,deltaX,deltaY,splitData[2]-'0');
        }
        answer[0] = yPos;
        answer[1] = xPos;
        return answer;
    }

    private char[][] makeCharArray(string[] park)
    {
        char[][] toCharPark = new char[park.Length][];

        for(int i = 0; i < toCharPark.Length; i++)
        {
            toCharPark[i] = park[i].ToCharArray();
        }
        return toCharPark;
    }

    private void findCurrentPos(in char[][] toCharPark,out int xPos, out int yPos)
    {
        bool find = false;
        xPos=0;
        yPos=0;
        for(int i=0;!find && i<toCharPark.Length; i++)
        {
            int index = Array.FindIndex<char>(toCharPark[i], x => x == 'S');
            if(index != -1)
            {
                yPos = i;
                xPos = index;
                find = true;
            }
        }
    }

    private void move(char[][] toCharPark,ref int xPos,ref int yPos,int deltaX,int deltaY,int moveCount)
    {
        int tempXpos = xPos;
        int tempYpos = yPos;
        for(int i=0;i<moveCount;i++)
        {
            int x = tempXpos+deltaX;
            int y = tempYpos+deltaY;
            if( y < 0 || y >= toCharPark.Length ||  x < 0 || x >= toCharPark[0].Length)
                return;
                
            if(toCharPark[y][x] == 'X')
                return;
            else
            {
                tempXpos = x;
                tempYpos = y;
            }
            
        }
        toCharPark[yPos][xPos] = 'O';
        toCharPark[tempYpos][tempXpos] = 'S';
        xPos = tempXpos;
        yPos = tempYpos;
    }

    private void print(in char[][] toCharPark)
    {
        for(int i=0;i<toCharPark.Length;i++)
        {
            for(int j=0;j<toCharPark[i].Length;j++)
            {
                Console.Write(toCharPark[i][j]);
            }
            Console.WriteLine();
        }
    }
    private static bool checkEqulity(int[] answer, int[] result)
    {
        return Enumerable.SequenceEqual<int>(answer,result);
    }
}