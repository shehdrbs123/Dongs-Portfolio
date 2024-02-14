#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while(true)
    {
        stack<char> s{};
        string input;
        bool isRight = true;
        
        getline(cin,input);
        if(input==".")
            break;
        
        int size = input.size();
        for(int i=0;i<size;++i)
        {
            if(input[i] == '(' || input[i] == '[' )
                s.push(input[i]);
            else if(input[i] == ')')
            {
                if(!s.empty())
                {
                    char top = s.top();
                    if(top == '(')
                        s.pop();
                    else
                    {
                        isRight = false;
                        break;
                    }
                }else
                {
                    isRight = false;
                    break;
                }
                
            }
            else if (input[i] == ']')
            {
                if(!s.empty())
                {
                    char top = s.top();
                    if(top == '[')
                        s.pop();
                    else
                    {
                        isRight = false;
                        break;
                    }
                }else
                {
                    isRight = false;
                    break;
                }
              
            }
        }
        
        if(s.size() > 0)
            isRight = false;
    
        if(isRight)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    
}