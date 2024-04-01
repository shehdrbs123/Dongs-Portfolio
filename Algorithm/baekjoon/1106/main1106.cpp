#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C,N;

bool comparePair(pair<int,int>& a, pair<int,int>& b)
{
    float aRate = (float)a.second/(float)a.first;
    float bRate = (float)b.second/(float)b.first;
    return aRate > bRate;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> C >> N;
    
    vector<pair<int,int>> v(N);

    int preCount;
    int preCost;
    int prePerson;

    for(int i=0;i<N;++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(),v.end(),comparePair);
    
    vector<int> dp(N);

    preCount = ceil((float)C/v[0].second) * v[0].first;
    preCost = preCount * v[0].first;
    prePerson = preCount * v[0].second;

    dp[0] = preCount;
    for(int i=1;i<N;++i)
    {
        

        for(int j=1;j<=preCount;++i)
        { 
            int restPerson = C - (prePerson - v[i-1].second * i);
            int currentCount = ceil((float)restPerson/(float)v[i].second);
            int currentCost = preCost - v[i-1].second * i + v[i] * currentCount;
        }

        preCount = dp[i];
    }
    
    cout << preCost;
}