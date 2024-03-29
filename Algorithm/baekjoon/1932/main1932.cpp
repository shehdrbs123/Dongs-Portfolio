#include <iostream>
#include <cmath>

using namespace std;

int N;
int triangle[501][501];
int dp[501][501];

void print(int v[][501],int N)
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<i+1;j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<i+1;++j)
        {
            cin >> triangle[i][j];
        }
    }

    dp[0][0] = triangle[0][0];
    
    for(int i=0;i<N-1;++i)
    {
        for(int j=0;j<i+1;++j)
        {
            int left = dp[i][j] + triangle[i+1][j];
            int right = dp[i][j] + triangle[i+1][j+1];

            dp[i+1][j] = max(dp[i+1][j], left);
            dp[i+1][j+1] = max(dp[i+1][j+1],right);
        }
    }
    
    int result = 0;
    for(int j=0;j<N;++j)
    {
        result = max(dp[N-1][j],result);
    }
    
    cout << result;
}