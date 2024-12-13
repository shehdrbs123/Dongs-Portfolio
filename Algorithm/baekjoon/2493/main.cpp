#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;

    stack<pair<int,int>> s{};
    
    for(int i=0;i<num;++i)
    {
        int n;
        cin >> n;

        while(!s.empty())
        {
            if(s.top().first < n)
                s.pop();
            else
                break;
        }

        if(s.empty())
        {
            cout << 0 << ' ';
        }else
        {
            cout << s.top().second << ' ';
        }
        s.emplace(n,i+1);
    }
}