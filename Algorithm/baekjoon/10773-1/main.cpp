#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    stack<long long> s{};
    int result=0;

    for(int i=0;i<num;++i)
    {
        long long n;
        cin >> n;
        if(n == 0)
        {
            long long n = s.top(); s.pop();
            result -= n;
            continue;
        }
        
        s.emplace(n);
        result+=n;
    }
    cout << result;
}