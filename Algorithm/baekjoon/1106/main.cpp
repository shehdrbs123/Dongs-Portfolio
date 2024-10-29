#include <iostream>
#include <cmath>
using namespace std;
int C;
int N;
int dat[21][2];
int dp[21][21][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> N;
    
    for(int i=1;i<=N;++i)
    {
        cin >> dat[i][0] >> dat[i][1];
    }
 
    for(int i=1;i<=C;++i)
    {
        for(int j=1;j<=N;++j)
        {
            int curValue=dat[j][0];
            int curCount=dat[j][1];
            int prePosY = i;
            int prePosX = j-1;
            int prePosValue = dp[prePosY][prePosX][0];
            int prePosCount = dp[prePosY][prePosX][1];
            
            int prePos2Y = i-dat[j][2] < 0 ? 0 : i-dat[j][2];
            int prePos2Value = dp[prePos2Y][prePosX][0];
            int prePos2Count = dp[prePos2Y][prePosX][1];

            int NeedPerson = j-prePosCount;
            int addShare = (int)ceil((float)NeedPerson/curCount);
            cout << addShare << '\n';
            prePos2Value += addShare * curValue;
            prePos2Count += addShare * curCount;
            
            cout << prePos2Value << " " << prePos2Count << "\n";
            int resultValue = 0;
            int resultCount = 0;

            if(prePosValue == 0)
            {
                dp[i][j][0] = prePos2Value;
                dp[i][j][1] = prePos2Count;
                continue;
            }
                

            if(prePosValue > prePos2Value)
            {
                resultValue = prePos2Value;
                resultCount = prePos2Count;
            }else if(prePosValue < prePos2Value)
            {
                resultValue = prePosValue;
                resultCount = prePosCount;
            }else
            {
                if(prePos2Count > prePosCount)
                {
                    resultValue = prePos2Value;
                    resultCount = prePos2Count;
                }else
                {
                    resultValue = prePosValue;
                    resultCount = prePosCount;
                }   
            }
            
            dp[i][j][0] = resultValue;
            dp[i][j][1] = resultCount;

        }
    }

    for(int i=0;i<=C;++i)
    {
        for(int j=0;j<=N;++j)
        {
            cout << dp[i][j][0] << " " << dp[i][j][1] << " | ";
        }
        cout << '\n';
    }
    
    int result = dp[C][1][0];
    for(int i=2;i<N;++i)
    {
        if(result > dp[C][i][0])
        {
            result = dp[C][i][0];
        }
    }

    cout << result;
    
}