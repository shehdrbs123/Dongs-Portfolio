#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    vector<int> v(num);
    stack<int> s{};

    for(int i=0;i<num;++i)
    {
        cin >> v[i];
    }
    
    for(int i=num-1; i>=0;--i)
    {
        int num2 = v[i];
        while(!s.empty())
        {
            if(num2 < s.top())
                break;
            s.pop();
        }

        if(s.empty())
        {
            v[i] = -1;
        }
        else
        {
            v[i] = s.top();
        }

        s.push(num2);
    }

    for(int i=0;i<num;++i)
    {
        cout << v[i] << ' ';
    }


}