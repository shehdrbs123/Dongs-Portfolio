#include <iostream>

using namespace std;

int C;
int N;

int amount[21];
int cost[21];
int dp[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //dp의 점화식은
    //i만큼의 비용을 들여서 얻을수 있는 고객의 최대치 dp[i]인 것이지
    //비용이 작은 것부터 큰것까지 올라가므로, 밑에서 C가 처음나오면 계산을 끝내고 내려가도 됨
    cin >> C >> N;
    for(int i=1;i<=N;++i)
    {
        cin >> cost[i] >> amount[i];
    }

    for(int i=1;i<=C;++i)
    {
        for(int j=1;j<=N;++j)
        {
            if(i-cost[j] >= 0)
            {
                dp[i] = max(dp[i], dp[i-cost[j]]+amount[j]);
            }
        }
    }

    for(int i=1;i<=100001;++i)
    {
        if(dp[i] >= C)
        {
            cout << i;
            break;
        }
    }
    return 0;
}