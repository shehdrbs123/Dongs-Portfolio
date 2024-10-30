#include <iostream>
#include <queue>
#include <memory.h>
#include <tuple>
using namespace std;

int testCase;
int len;
int sx,sy;
int ex,ey;
int dx[] = {-1, 1, 2,2,1,-1,-2,-2};
int dy[] = {-2,-2,-1,1,2, 2,1 ,-1};
int board[301][301];

void print(int len)
{
    for(int i=0;i<len;++i)
    {
        for(int j=0;j<len;++j)
        {
            cout << board[i][j] << ' ';        
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> testCase;

    for(int i=0;i<testCase;++i)
    {
        cin >> len;
        cin >> sx >> sy;
        cin >> ex >> ey;   
        if(sx == ex && sy == ey)
        {
            cout << 0 << '\n';
            continue;
        }     
        
        queue<pair<int,int>> q;

        q.emplace(sx,sy);
        board[sy][sx] = 1;
        
        bool find=false;

        while(!q.empty() && !find)
        {
            auto pos = q.front(); q.pop();
            int sx,sy;
            tie(sx,sy) = pos;
            
            for(int dir=0;dir<8;++dir)
            {
                int nx = dx[dir] + sx;
                int ny = dy[dir] + sy;
                
                if(nx < 0|| nx>=len || ny < 0 || ny >=len) continue;
                if(board[ny][nx] > 0) continue;
                if(nx == ex && ny == ey)
                {
                    find = true;
                    cout << board[sy][sx] << '\n';
                    break;
                }
                
                q.emplace(nx,ny);
                board[ny][nx] = board[sy][sx]+1;
                
            }
        }

        for(int j=0;j<len;++j)
        {
            memset(board,0,(len*sizeof(int))+(301*j*sizeof(int)));
        }
    }
}