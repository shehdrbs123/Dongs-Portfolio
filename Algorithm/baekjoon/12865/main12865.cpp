#include <iostream>
#include <vector>
#define we first;
#define vv second;

using namespace std;
int N,K;

int dp[100001][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    vector<pair<int,int>> v{};
    v.reserve(N);
    
    for(int i=0;i<N;++i)
    {
        int w,V;
        cin >> w >> V;
        v.emplace_back(w,V);
    }
    int result = 0;
    for(int i=1;i<=K;++i)
    {
        for(int j=1;j<=N;++j)
        {
            dp[i][j] = dp[i][j-1];
            int preweight = i - v[j-1].we;
            if(preweight>=0)
            {
                int value = dp[preweight][j-1] + v[j-1].vv;
                dp[i][j] = max(dp[i][j],value);
            }
            result = max(result,dp[i][j]);
        }
    }
    
    cout << result;
    
}