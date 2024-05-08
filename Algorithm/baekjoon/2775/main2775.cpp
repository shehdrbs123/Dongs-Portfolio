#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;

int dp[15][15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    vector<pair<int,int>> v(N);
    int maxColumn = -1;
    int maxRow = -1;
    for(int i=0;i<N;++i)
    {
        cin >> v[i].first;
        cin >> v[i].second;
        maxRow = max(maxRow,v[i].first);
        maxColumn = max(maxColumn,v[i].second);
    }
    for(int i=1;i<=maxColumn;++i)
    {
        dp[0][i] = i;
    }
    
    for(int i=1;i<=maxRow;++i)
    {
        for(int j=1;j<=maxColumn;++j)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
       
    for(auto a : v)
    {
        cout << dp[a.first][a.second] << '\n';
    }
}