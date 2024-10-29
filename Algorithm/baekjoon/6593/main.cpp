#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>


using namespace std;

int L, R, C;

char field[31][31][31];
int visited[31][31][31];

int dx[] = {0,1,0,-1,0,0};
int dy[] = {1,0,-1,0,0,0};
int dz[] = {0,0,0,0,1,-1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        int sX,sY,sZ;
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0)
            return 0;

        memset(visited,0,sizeof(int)*31*31*31);
        for(int i=0;i<L;++i)
        {
            for(int j=0;j<R;++j)
            {
                for(int k=0;k<C;++k)
                {
                    cin >> field[i][j][k];
                    if(field[i][j][k] == 'S')
                    {
                        sZ = i;
                        sY = j;
                        sX = k;
                    }
                }
            }
        }

        queue<tuple<int,int,int>> q{};
        q.emplace(sZ,sY,sX);

        visited[sZ][sY][sX] = 1;
        bool isFound = false;

        while(!q.empty() && !isFound)
        {
            int x,y,z;
            tie(z,y,x) = q.front();
            q.pop();

            for(int dir=0;dir<6;++dir)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];

                if(nx<0 || nx >= C || ny<0 || ny>=R || nz<0 || nz>=L ) continue;
                if(visited[nz][ny][nx] > 0) continue;
                if(field[nz][ny][nx] == '#') continue;
                if(field[nz][ny][nx] == 'E') 
                {
                    cout << "Escaped in " << visited[z][y][x] << " minute(s)." << '\n';
                    isFound = true;
                    break;
                }
                
                visited[nz][ny][nx] = visited[z][y][x]+1;
                q.emplace(nz,ny,nx);
            }
        }
        
        if(!isFound)
        {
            cout << "Trapped!" << '\n';
        }
    }
}