#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    stack<int> s{};
    
    for(int i=0;i<num;++i)
    {
        string action;
        int num;
        cin >> action;
        
        if(action == "push")
        {
            cin >> num;
            s.emplace(num);
        }else if(action == "pop")
        {
            int num = -1;
            if(!s.empty())
            {
                num = s.top(); s.pop();
            }
            cout << num << '\n';
        }else if(action == "size")
        {
            cout << s.size() << '\n';
        }else if(action == "empty")
        {
            int num = 0;
            if(s.empty())
                num = 1;
            cout << num << '\n';   
        }
        else
        {
            int num = -1;
            if(!s.empty())
                num = s.top();
            cout << num << '\n';
        }
    }
}