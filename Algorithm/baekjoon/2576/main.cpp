#include <iostream>

using namespace std;

int N;

int dat[302];
int dp[302][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=1; i<=N;++i)
    {
        cin >> dat[i];
    }
    
    dp[1][1] = 10;
    dp[1][2] = 10;
    for(int i=2;i<=N;++i)
    {
        dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + dat[i];
        dp[i][2] = dp[i-1][1] + dat[i];
    }
    
    cout << max(dp[N][1],dp[N][2]) << '\n';
}