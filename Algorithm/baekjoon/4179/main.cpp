#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string field[1002];
int fire[1002][1002];
int person[1002][1002];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    for(int i=0;i<r;++i)
    {
        fill(fire[i],fire[i]+c,-1);
        fill(person[i],person[i]+c,-1);
    }

    pair<int,int> J{};
    queue<pair<int,int>> q{};
    
    for(int i=0;i<r;++i)
    {
        cin >> field[i];
        for(int j=0;j<c;++j)
        {
            if(field[i][j] == 'J')
            {
                J.X = i;
                J.Y = j;
                person[i][j] = 0;
            }
            else if(field[i][j] == 'F')
            {
                q.emplace(i,j);
                fire[i][j] = 0;
            }
        }
    }

    //불의 이동 표기
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();
        for(int dir = 0; dir<4; ++dir)
        {
            int nx = pos.X + dx[dir];
            int ny = pos.Y + dy[dir];
            
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if(field[nx][ny] == '#' || fire[nx][ny] != -1) continue;
            
            fire[nx][ny] = fire[pos.X][pos.Y] +1;
            q.emplace(nx,ny);
        }
    }

    //지훈의 이동 표기
    q.emplace(J.X,J.Y);
    fire[J.X][J.Y] = 0;
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();

        for(int dir = 0; dir<4; ++dir)
        {
            int nx = pos.X + dx[dir];
            int ny = pos.Y + dy[dir];
           
            if(nx<0 || nx>=r || ny<0 || ny>=c)
            {
                cout << person[pos.X][pos.Y]+1;
                return 0;
            }
            if(person[nx][ny]>=0 || field[nx][ny] == '#') continue;
            if(fire[nx][ny] >= 0 && fire[nx][ny] <= person[pos.X][pos.Y]+1) continue;
            
            person[nx][ny] = person[pos.X][pos.Y]+1;
            q.emplace(nx,ny);
        }
    }

    cout << "IMPOSSIBLE";
}