#include <bits/stdc++.h>

using namespace std;

int box[101][101][101];
bool visited[101][101][101];
int m,n,h;
int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;
    cin.ignore(1);
    string input;
    queue<tuple<int,int,int>> q{};
    int totalTomatoCount=0;
    int ripeTomatoCount=0;
    int maxDay=1;

    for(int k=0;k<h;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                {
                    ++totalTomatoCount;
                    ++ripeTomatoCount;
                    q.emplace(i,j,k);
                    visited[i][j][k] = true;
                }else if(box[i][j][k] == 0)
                {
                    ++totalTomatoCount;
                }
            }
        }
    }

    if(totalTomatoCount == ripeTomatoCount)
    {
        cout << '0';
        return 0;
    }
        
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();
        int x = get<0>(pos);
        int y = get<1>(pos);
        int z = get<2>(pos);

        for(int dir=0;dir<6;++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if(nx < 0 || nx >=n || ny < 0 || ny >=m || nz < 0 || nz >=h) continue;
            if(box[nx][ny][nz] > 0 || box[nx][ny][nz] == -1 || visited[nx][ny][nz]) continue;

            box[nx][ny][nz] = box[x][y][z] +1;
            visited[nx][ny][nz] = true;
            q.emplace(nx,ny,nz);

            maxDay = max(box[nx][ny][nz],maxDay);
            ++ripeTomatoCount;
        }
    }
    
    if(totalTomatoCount > ripeTomatoCount)
        maxDay = 0;

    cout << maxDay -1;   
    
}