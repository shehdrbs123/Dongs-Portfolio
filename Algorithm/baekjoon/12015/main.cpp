#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1000001];
int num[1000001];
int element[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        cin >> num[i];
    }
    
    int dpIdx=1;
    dp[0] = 1;
    element[0] = num[0];
    
    for(int i=1;i<N;++i)
    {
        if(element[dpIdx-1]<num[i])
        {
            dp[dpIdx] = dp[dpIdx-1]+1;
            element[dpIdx] = num[i];
            ++dpIdx;
            
        }else
        {
            int mid = dpIdx/2;
            while(mid > 0 && element[mid] >= num[i]){
                mid/=2;
            }
            if(mid != 0 || element[mid] != num[i])
                element[mid+1] = num[i];    
        }
        
    }

    cout << dp[dpIdx-1] << '\n';
}
