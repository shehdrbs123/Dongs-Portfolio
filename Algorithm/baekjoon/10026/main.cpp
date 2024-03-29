#include <bits/stdc++.h>

using namespace std;

string field[100];

bool visited[100][100];
bool uVisited[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> field[i];
    }
    
    queue<pair<int,int>> q{};
    
    int colorCount=0;
    int uColorCount=0;
   
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(visited[i][j] == true)
                continue;
            
            char selected = field[i][j];
            
            q.emplace(i,j);
            visited[i][j] = true;
            ++colorCount;
            while(!q.empty())
            {
                auto pos = q.front(); q.pop();
                
                for(int dir=0;dir<4;++dir)
                {
                    int nx = pos.first + dx[dir];
                    int ny = pos.second + dy[dir];
                    
                    if(nx<0 || nx >=n || ny<0 || ny >=n) continue;
                    if(visited[nx][ny] == true) continue;
                    if(selected != field[nx][ny]) continue;

                    q.emplace(nx,ny);
                    visited[nx][ny] = true;
                }
            }

            if(uVisited[i][j] == true)
                continue;
            
            q.emplace(i,j);
            uVisited[i][j] = true;
            ++uColorCount;

            while(!q.empty())
            {
                auto pos = q.front(); q.pop();
                
                for(int dir=0;dir<4;++dir)
                {
                    int nx = pos.first + dx[dir];
                    int ny = pos.second + dy[dir];
                    
                    if(nx<0 || nx >=n || ny<0 || ny >=n) continue;
                    if(uVisited[nx][ny] == true) continue;
                    if(selected == 'R' || selected == 'G' )
                    {
                        if(field[nx][ny] == 'B')
                            continue;
                    }else if (selected != field[nx][ny])
                    {
                        continue;
                    } 
                    
                    q.emplace(nx,ny);
                    uVisited[nx][ny] = true;
                }
            }
        }
    }  
    cout << colorCount << " " << uColorCount;
}