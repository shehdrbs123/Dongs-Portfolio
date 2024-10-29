#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string pipe;
    cin >> pipe;
    
    stack<char> s;
    int result = 0;
    for(int i=0;i<pipe.size();++i)
    {
        char c = pipe[i];
        if(c == '(')
        {
            s.push(c);    
        }
        else if(c == ')')
        {
            if(pipe[i-1] == '(')
            {
                
                int count = s.size()-1;
                result+=count;
            }else
            {
                result+=1;
            }     
            s.pop();
        }
    }
    cout << result;
}