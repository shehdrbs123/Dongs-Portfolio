#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int field[502][502];
bool visited[502][502];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int,int>> q;
    
    int n,m;
    cin >> n >> m;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> field[i][j];
        }
    }
    int printCount = 0;
    int maxArea = 0;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<m; ++j)
        {
            if(field[i][j] == 0 || visited[i][j]) continue;
            
            q.push({i,j});
            visited[i][j] = true;
            int area = 1;
            while(!q.empty())
            {
                auto pos = q.front(); q.pop();
                
                for(int dir = 0;dir< 4; ++dir)
                {
                    int nx = pos.X + dx[dir];
                    int ny = pos.Y + dy[dir];
                    
                    if(field[nx][ny] == 0 || visited[nx][ny]) continue;
                    
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    ++area;
                }
            }
            maxArea = max(area,maxArea);
            ++printCount;
        }
    }
    cout << printCount << '\n' << maxArea;
}