#include <bits/stdc++.h>

using namespace std;
int N, K;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    vector<int> v(N);
    for(int i=0;i<N;++i)
    {
        cin >> v[i];
    }
    
    priority_queue<int,vector<int>,greater<int>> q(v.begin(),v.end());
    
    cin >> K;
    int smallRange=0;
    int largeRange=0;
    bool isRangeIn = false;
    int result = 0;
    while(!q.empty())
    {
        int num = q.top(); q.pop();
        if(num == K) 
        {
            cout << 0; 
            return 0;
        }
        if(num < K)
        {
            smallRange = num;
        }
        else
        {
            largeRange = num;
            break;
        }
    }
    
    for(int i=smallRange+1;i<largeRange-1;++i)
    {
       for(int j=i+1;j<largeRange;++j)
       {
           if(i <= K && K <= j) ++result;
       } 
    }
    
    cout << result;
    
}