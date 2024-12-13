#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    int currentCount=1;
    stack<int> s{};
    queue<char> q{};
    
    for(int i=0;i<num;++i)
    {
        int targetN;
        cin >> targetN;
        while(true)
        {
            if(s.empty())
            {
                s.emplace(currentCount++);
                q.emplace('+');
                continue;
            }
            int top = s.top();
                
            if(top < targetN)
            {
                s.emplace(currentCount++);
                q.emplace('+');
            }
            else if( top == targetN)
            {
                q.emplace('-');
                s.pop();
                break;
            }else
            {
                cout << "NO";
                return 0 ;
            }
        }
    }
    
    while(!q.empty())
    {
        cout << q.front() << '\n';
        q.pop();
    }
}