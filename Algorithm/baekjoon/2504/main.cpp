#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    
    cin >> input;
    stack<char> s{};
    int result=0;
    int num = 1;
    //분배 법칙을 이용한 방법
    for(int i=0;i<input.size();++i)
    {
       if(input[i] == '(')
       {           
           s.emplace(input[i]);   
           num*=2;
       }else if(input[i] == '[')
       {
           s.emplace(input[i]);
           num*=3;
       }else if(input[i] == ']')
       {
           if(s.empty() || s.top() != '[')
           {
               cout << 0;
               return 0;
           }
           if(input[i-1] == '[') result+=num;
           s.pop();
           num/=3;
           
       }else
       {
           if(s.empty() || s.top() != '(')
           {
               cout << 0;
               return 0;
           }
           if(input[i-1] == '(') result+=num;
           s.pop();
           num/=2;
       }
    }
    
    if(s.empty())
        cout << result;
    else
        cout << 0;
}