#include <iostream>
#include <queue>
#include <memory.h>
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

        queue<pair<int,int>> q;
        bool visited[N+1];

        memset(visited,0,sizeof(visited));

        q.emplace(s,0);
        visited[s] = true;

        while(!q.empty())
        {
            auto n = q.front(); q.pop();
            int dest = n.first;
            int length = n.second;
            int result = dp[dest][e] + length; 

            if(dp[dest][e] != 0)
            {
                cout << result << '\n';
                break;
            }

            for(int j=1;j<=N;++j)
            {
                if(!visited[j] && dp[dest][j] != 0)
                {
                    visited[j] = true;
                    q.emplace(j,length + dp[dest][j]);
                }
            }
        }
    }
   
}