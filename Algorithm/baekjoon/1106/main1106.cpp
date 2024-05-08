#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    for(int i=0;i<N;++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    
}