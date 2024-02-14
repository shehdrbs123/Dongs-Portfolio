#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second != b.second)
        return a.second < b.second;
    
    if(a.first != b.first)
        return a.first < b.first;

    int agap = a.second - a.first;
    int bgap = b.second - b.first;
    return agap < bgap;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int c;
    cin >> c;
    
    vector<pair<int,int>> v(c);
    
    for(int i=0;i<c;++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), cmp);
    int nextStart = v[0].second;
    int count=1;
    for(int i=1;i<c;++i)
    {
        if(nextStart> v[i].first) continue;
        count++;
        nextStart = v[i].second;
    }
    cout << count;
}