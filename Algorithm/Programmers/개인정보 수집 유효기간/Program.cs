// See https://aka.ms/new-console-template for more information
using System;


public class Solution {
    public static void Main(string[] args)
    {
        string today = "2020.01.01";
        string[] terms = {"Z 3", "D 5"};
        string[] privacies = {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"};
        int[] result = {1,4,5};
        int[] answer;
        Solution sol = new Solution();
        answer = sol.solution(today, terms,privacies);

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
    public int[] solution(string today, string[] terms, string[] privacies)
    {       
        List<int> tempAnswer = new List<int>();
        Dictionary<string,int> termsDic = new Dictionary<string, int>();

        string[] todaySplit = today.Split('.');
        int[] answer  = new int[]{};
        int todayCount=0;

        //데이터 가공
        todayCount += (Convert.ToInt32(todaySplit[0])-1) * 336;
        todayCount += (Convert.ToInt32(todaySplit[1])-1) * 28;
        todayCount += (Convert.ToInt32(todaySplit[2]));

        //글자찾기 find로 찾는거 별로라서 dictionary로 가공함
        Array.ForEach<string>(terms, (x) => 
        {
            string[] data = x.Split(' ');
            termsDic.Add(data[0],Convert.ToInt32(data[1])*28);
        });

        for(int i=0;i<privacies.Length;i++)
        {
            string[] splitString = privacies[i].Split(' ');
            string[] dateSplit = splitString[0].Split('.');

            int allDay = 0;
            allDay += (Convert.ToInt32(dateSplit[0])-1) * 336;
            allDay += (Convert.ToInt32(dateSplit[1])-1) * 28;
            allDay += (Convert.ToInt32(dateSplit[2])-1);
            allDay += termsDic[splitString[1]];
            Console.WriteLine(allDay + " " + todayCount);
            if(allDay < todayCount)
            {
                tempAnswer.Add(i+1);
            }
            
        }
        answer = tempAnswer.ToArray();
        
        return answer; 
    }


    // public int[] solution(string today, string[] terms, string[] privacies) {
    //     int[] answer = new int[]{};
    //     DateTime dtToday;
    //     int privaciesLength;
    //     Dictionary<string,int> termsDic = new Dictionary<string, int>();
    //     List<int> tempList = new List<int>();

    //     dtToday = GetDateTime(today,'.');
    //     privaciesLength = privacies.Length;

    //     // terms 데이터를 Dictionary로 가공해서 사용
    //     Array.ForEach<string>(terms, (x) => 
    //     {
    //         string[] data = x.Split(' ');
    //         termsDic.Add(data[0],Convert.ToInt32(data[1])*28);
    //     });
        

    //     for(int i=0; i<privaciesLength; i++)
    //     {
    //         string[] dateAndTerms = privacies[i].Split(' ');
    //         DateTime dtPreDay = GetDateTime(dateAndTerms[0],'.');
    //         string termsString = dateAndTerms[1];
    //         int passed=-1;

    //         if(termsDic.TryGetValue(termsString, out passed))
    //         {
    //             dtPreDay = dtPreDay.AddDays(passed);
    //             Console.WriteLine(dtPreDay.ToString() + " " + dtToday);
    //             if(DateTime.Compare(dtToday,dtPreDay) < 0)
    //             {
    //                 tempList.Add(i);
    //             }
    //         }
    //     }

        
    //     answer = tempList.ToArray();
    //     return answer;
    // }
    // //year, month, day 만 가능
    // private DateTime GetDateTime(string date,char split)
    // {
    //     int year;
    //     int month;
    //     int day;
    //     string[] splitDate = date.Split(split);
    //     year = Convert.ToInt32(splitDate[0]);
    //     month = Convert.ToInt32(splitDate[1]);
    //     day = Convert.ToInt32(splitDate[2]);
    //     return new DateTime(year,month,day);
    // }
}