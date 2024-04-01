#include <iostream>

using namespace std;


int field[51][51];

int N, M;
int r, c, dir;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result=0;

    cin >> N >> M;
    cin >> r >> c >> dir;
    
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin >> field[i][j];
        }
    }
    
    while(true)
    {
        if(field[r][c] == 0)
        {
            field[r][c] = 2;
            ++result;
        }
        int needClean = -1;
        for(int dir2=0;dir2<4;++dir2)
        {
            int nx = c + dx[dir2];
            int ny = r + dy[dir2];

            if(field[ny][nx] == 0)
            {
                needClean = dir2;
                break;
            }
        }
        
        if(needClean == -1)
        {
            int backdir = (dir+2)%4;
            
            int nx = c + dx[backdir];
            int ny = r + dy[backdir];

            if(field[ny][nx] == 1) break;
            if(r<0 || r>=N || c <0 || c >=M) break;

            c = nx;
            r = ny;
            
            continue;
        }
        
        dir = (dir+3)%4;
        int nx = c + dx[dir];
        int ny = r + dy[dir];
        if(ny<0 || ny>=N || nx<0 || nx >=M) continue;
        if(field[ny][nx] == 0)
        {
            r = ny;
            c = nx;
        }
    }

    cout << result;
}