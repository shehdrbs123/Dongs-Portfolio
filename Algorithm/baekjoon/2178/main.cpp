#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int field[102][102];
int visited[102][102];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    
    cin >> n >> m;
    
    for(int i=1;i<=n;++i)
    {
        string str;
        cin >> str;
        for(int j=0;j<m;++j)
        {
            field[i][j+1] = str[j]-'0';
        }
    }
        
            
    
    queue<pair<int,int>> q{};
    
    q.push({1,1});
    visited[1][1] = 1;
    
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();
        
        for(int dir = 0; dir<4; ++dir)
        {
            int nx = pos.X + dx[dir];
            int ny = pos.Y + dy[dir];
            
            if(field[nx][ny] == 0 || visited[nx][ny]>0) continue;
            
            q.push({nx,ny});
            visited[nx][ny] = visited[pos.X][pos.Y]+1;           
        }
    }
    
    cout << visited[n][m];
}
