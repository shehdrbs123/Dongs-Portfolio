#include <bits/stdc++.h>

using namespace std;

int n,k,t0;
int degree[1001];
int result;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> k >> t0;
    
    for(int i=0;i<n;++i)
    {
        cin >> degree[i];
    }
    
    int curDegree = t0;
    
    for(int i=0;i<n;++i)
    {
        int add = abs(curDegree - k);
        if(curDegree > k)
            add *= -1;
        
        curDegree = curDegree + degree[i] + add;
        result += curDegree - k;
    }

    cout << result;
}