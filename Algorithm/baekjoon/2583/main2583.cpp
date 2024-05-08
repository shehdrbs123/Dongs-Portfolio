#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;;

bool board[101][101];
bool visited[101][101];
int M,N,K;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N >> K;
    
    for(int i=0;i<K;++i)
    {
        int sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;
        
        for(int j=sy;j<ey;++j)
        {
            for(int k=sx;k<ex;++k)
            {
                board[j][k] = true;
            }
        }
    }
    
    vector<int> vCount;
    
    for(int i=M-1;i>=0;--i)
    {
        for(int j=0;j<N;++j)
        {
            if(!board[i][j] && !visited[i][j])
            {
                queue<pair<int,int>> q;
                q.emplace(j,i);
                visited[i][j] = true;

                int count=0;
                while(!q.empty())
                {
                    auto pos = q.front();q.pop();
                    ++count;

                    for(int dir=0;dir<4;++dir)
                    {
                        int nx = pos.first + dx[dir];
                        int ny = pos.second + dy[dir];

                        if(nx<0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(board[ny][nx] || visited[ny][nx]) continue;

                        visited[ny][nx] = true;
                        q.emplace(nx,ny);

                    }
                }
                vCount.emplace_back(count);
            }
        }
    }
    
    sort(vCount.begin(),vCount.end(),less<int>());

    cout << vCount.size() << '\n';
    
    for(auto num : vCount)
    {
        cout << num <<' ';
    }    
}