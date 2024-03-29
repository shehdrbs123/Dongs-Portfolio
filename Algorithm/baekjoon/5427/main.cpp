#include <bits/stdc++.h>

using namespace std;

int N;
int r,c;
string field[1001];
int visited[1001][1001];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        queue<pair<int,int>> q{};
        pair<int,int> s;
        cin >> c >> r;

        for(int j=0;j<r;j++)
        {
            fill(visited[j],visited[j]+c,-1);
        }

        for(int j=0;j<r;++j)
        {
            cin >> field[j];
            for(int k=0;k<c;++k)
            {
                if(field[j][k] == '*')
                {
                    q.emplace(j,k);
                    visited[j][k] = 0;
                }else if(field[j][k] == '@')
                {
                    s.first = j;
                    s.second = k;
                }
            }
        }
        
        
        while(!q.empty())
        {
            auto pos = q.front(); q.pop();
            int time = visited[pos.first][pos.second]+1;
            for(int dir = 0; dir<4; ++dir)
            {
                int nx = pos.first + dx[dir];
                int ny = pos.second + dy[dir];
                
                if(nx<0 || nx>= r || ny < 0 || ny >= c) continue;
                if(field[nx][ny] == '#' || visited[nx][ny] >= 0) continue;
                
                q.emplace(nx,ny);
                visited[nx][ny] = time;
            }
        }

        // cout << "fire" << '\n';
        // for(int j=0;j<r;++j)
        // {
        //     for(int k=0;k<c;++k)
        //     {
        //         cout << visited[j][k] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << endl;
        
        q.emplace(s.first,s.second);
        visited[s.first][s.second] = 0;
        bool isEscape = false;
        int maxTime;
        while(!q.empty())
        {
            auto pos = q.front(); q.pop();
            int time = visited[pos.first][pos.second]+1;

            for(int dir = 0; dir<4; ++dir)
            {
                int nx = pos.first + dx[dir];
                int ny = pos.second + dy[dir];
                
                if(nx<0 || nx >= r || ny < 0 || ny >= c) 
                {
                    cout << time << '\n';
                    isEscape = true;
                    break;
                }
                if(field[nx][ny] == '#' || visited[nx][ny] != -1 && visited[nx][ny] <= time) continue;
                
                q.emplace(nx,ny);
                visited[nx][ny] = time;
            }
            if(isEscape)
                break;
        }
        
        // for(int j=0;j<r;++j)
        // {
        //     for(int k=0;k<c;++k)
        //     {
        //         cout << visited[j][k] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << endl;

        if(!isEscape)
            cout << "IMPOSSIBLE" << '\n';
        
    }
    
}