#include <iostream>

using namespace std;

int N;
int dp[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    dp[1] = 0;
    for(int i=2;i<=N;++i)
    {
        int a=1000002;
        int b=1000002;
        int c=1000002;
        int result;
        if(i%3 == 0)
        {
            a = dp[i/3] + 1;
        }
        if(i%2 == 0)
        {
            b = dp[i/2] + 1;
        }
        c= dp[i-1]+1;
        result = min(a,b);
        result = min(result,c);
        dp[i] = result;
    }
    
    cout << dp[N];
    
}