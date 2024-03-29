#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int field[1002][1002];
int date[1002][1002];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int,int>> q{};
    
    int n,m;
    cin >> n >> m;
    int tomatoCount = n*m;
    int makeRipeTomato = 0;


    fill(date[0],date[0]+1000004,-1);
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int v;
            cin >> v;
            v += 1;
            field[i][j] = v;
            if(v == 2)
            {
                q.push({i,j});
                date[i][j] = 0;
                ++makeRipeTomato;
            }
            else if(v==0)
            {
                --tomatoCount;
            }
        }
    }
    
    int maxDate = 0;
    
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();
        int curDate = date[pos.X][pos.Y]+1;
        for(int dir=0;dir<4;++dir)
        {
            int nx = pos.X + dx[dir];
            int ny = pos.Y + dy[dir];
            
            if(field[nx][ny] == 0)  continue;
            if(date[nx][ny] >= 0) continue;

            q.push({nx,ny});
            if(field[nx][ny] != 2)
                ++makeRipeTomato;
            date[nx][ny] = curDate;
            maxDate = max(curDate,maxDate);
        }
    }
           
    if(tomatoCount > makeRipeTomato )
        maxDate= -1;
    
    cout << maxDate;
    
    //     maxDate = -1;
    // cout << maxDate;
}