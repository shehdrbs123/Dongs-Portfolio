#include <iostream>

using namespace std;

int N,M;

int dat[100002];

int dp[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=1;i<=N;++i)
    {
        cin >> dat[i];
    }
    
    for(int i=1;i<=N;++i)
    {
        dp[i] = dp[i-1]+dat[i];
    }
    
    for(int i=0;i<M;++i)
    {
        int s,e;
        cin >> s >> e;

        cout << dp[e]-dp[s-1] << '\n';
    }

}