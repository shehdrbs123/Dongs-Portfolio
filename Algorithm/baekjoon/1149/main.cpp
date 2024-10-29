#include <iostream>

using namespace std;

int N;
int dat[1001][3];
int dp[3][1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        cin >> dat[i][0] >> dat[i][1] >> dat[i][2];
    }

    dp[0][0] = dat[0][0];
    dp[1][0] = dat[0][1];
    dp[2][0] = dat[0][2];
    
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<3;++j)
        {
            int nextIdx = (j+1)%3;
            int ma = dat[i][j] + dp[nextIdx][i-1];

            nextIdx = (j+2)%3;
            dp[j][i] = min(ma,dat[i][j] + dp[nextIdx][i-1]);
        }
    }

    cout << min(min(dp[0][N-1],dp[1][N-1]),dp[2][N-1]);
}