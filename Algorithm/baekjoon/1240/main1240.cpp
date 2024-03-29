#include <iostream>
#include <queue>
using namespace std;

int N,M;

int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N-1;++i)
    {
        int s,e,l;
        cin >> s >> e >> l;
        
        dp[s][e] = l;
        dp[e][s] = l;
    }

    for(int i=0;i<M;++i)
    {
        int length = 0;
        int s, e;
        cin >> s >> e;
        
        if(dp[s][e] !=0 )
        {
            cout << dp[s][e] << '\n';
            continue;
        }
        if(dp[e][s] != 0)
        {
            cout << dp[e][s] << '\n';
            continue;
        }
            
        queue<pair<int,int>> q{};
        for(int i=1;i<=N;++i)
        {
            if(dp[s][i] != 0)
                q.emplace(i,dp[s][i]);
        }
        while(!q.empty())
        {
            auto p = q.front(); q.pop();            
            int dest = p.first;
            int length = p.second;
            int result = dp[dest][e] + length;            
            if(dp[dest][e] != 0)
            {
                cout << dp[dest][e] + length << '\n';
                dp[s][e] = result;
                dp[e][s] = result;
                break;
            }
            
            for(int i=1;i<=N;++i)
            {
                if(dp[dest][i] != 0)
                {
                    dp[s][i] = dp[dest][i] + length;
                    dp[i][s] = dp[dest][i] + length;
                }
            }          
        }
    }
    
}