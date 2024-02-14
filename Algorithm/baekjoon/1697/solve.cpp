#include <bits/stdc++.h>

using namespace std;
bool visited[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s, e, c;
    cin >> s >> e;
    
    queue<pair<int,int>> q{};
    c=0;
    q.emplace(s,c);
    visited[s] = true;

    while(!q.empty())
    {
        pair<int,int> p = q.front(); q.pop();
        if(p.first == e ) { c = p.second; break; } 
        
        int l = p.first -1;
        int r = p.first +1;
        int t = p.first * 2;
        int nC = p.second +1;
  
        if(l >= 0 && !visited[l]) { visited[l] = true; q.emplace(l,nC); }
        if(r <= 100000 && !visited[r]){ visited[r] = true; q.emplace(r,nC);}
        if(t <= 100000 && !visited[t]){ visited[t] = true; q.emplace(t,nC);}
    }
    cout << c;
    return 0;
}