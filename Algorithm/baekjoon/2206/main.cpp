#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N,M;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
string field[1001];
bool visited[2][1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N;++i)
    {
        cin >> field[i];
    }
    
    queue<tuple<int,int,int,bool>> q{};
    q.emplace(0,0,1,false);
    visited[0][0][0] = true;
    while(!q.empty())
    {
        int x,y,count;
        bool wall;
        tie(x,y,count,wall) = q.front(); 
        q.pop();
        
        if(x == N-1 && y == M-1)
        {
            cout << count;
            return 0;
        }
        
        count += 1;
        for(int dir=0;dir<4;++dir)
        {
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            
            if(nx<0 || nx >= N || ny<0 || ny >= M) continue;

            if(field[nx][ny] == '0')
            {
                if(!wall)
                {
                    if(visited[0][nx][ny]) continue;
                    visited[0][nx][ny] = true;
                    q.emplace(nx,ny,count,false);
                }else
                {
                    if(visited[1][nx][ny]) continue;
                    visited[1][nx][ny] = true;
                    q.emplace(nx,ny,count,true);
                }
            }else
            {
                if(!wall)
                {
                    visited[1][nx][ny] = true;
                    q.emplace(nx,ny,count,true);
                }
            }
        }
    }
    
    cout << -1;
    return 0;
}