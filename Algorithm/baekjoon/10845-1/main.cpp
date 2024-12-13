#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    queue<int> q;
    
    for(int i=0;i<num;++i)
    {
        string command;
        cin >> command;
        if(command == "push")
        {
            int n;
            cin >> n;
            q.emplace(n);
        }else if(command == "pop")
        {
            int n = -1;
            if(!q.empty())
            {
                n = q.front();
                q.pop();
            }
            cout << n << '\n';    
        }else if(command == "front")
        {
            int n = -1;
            if(!q.empty())
                n = q.front();
            cout << n << '\n';
            
        }else if(command == "back")
        {
            int n = -1;
            if(!q.empty())
                n = q.back();
            cout << n << '\n';
        }else if(command == "size")
        {
            cout << q.size() << '\n';
        }else
        {
            int num = 0;
            if(q.empty())
                num = 1;
            cout << num << '\n';
        }
    }
}