#include <iostream>
#include <vector>


using namespace std;

int N;
pair<int,int> dp[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    dp[1].first = 0;
    dp[1].second = 1;
   
    for(int i=2;i<=N;++i)
    {
        int result = dp[i-1].first+1;
        int preElement = i-1;
        
        if(i%3 == 0)
        {
            int element = i/3;
            int cal = dp[element].first+1;
            if(cal < result)
            {
                result = cal;
                preElement = element;
            }
        }
        
        if(i%2 == 0)
        {
            int element = i/2;
            int cal = dp[element].first+1;
            if(cal < result)
            {
                result = cal;
                preElement = element;
            }
        }
          
        dp[i].first = result;
        dp[i].second = preElement;
    }
    
    cout << dp[N].first << '\n';
    cout << N << ' ';
    int preElement = N;
    while(preElement != 1)
    {
        cout << dp[preElement].second << ' ';
        preElement = dp[preElement].second;
    }
}