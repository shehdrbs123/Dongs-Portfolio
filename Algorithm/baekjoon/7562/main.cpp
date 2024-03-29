#include <bits/stdc++.h>

using namespace std;

int N;
int l;
bool visited[301][301]{};
int dx[8] = {-2,-1, 1, 2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1, 1, 2,2,1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    
    for(int i=0;i<N;++i)
    {
        queue<tuple<int,int,int>> q{};
        int sx, sy;
        int tx, ty;
        cin >> l;
        cin >> sx >> sy;
        cin >> tx >> ty;

        for(int j=0;j<=l;++j)
        {
            for(int k=0;k<=l;++k)
            {
                visited[j][k] = false;
            }            
        }
        
        q.emplace(sx,sy,0);
        visited[sx][sy] = true;

        while(!q.empty())
        {
            auto pos = q.front(); q.pop();
            int x = get<0>(pos);
            int y = get<1>(pos);
            int distance = get<2>(pos);

            if(x == tx && y == ty)
            {
                cout << distance << '\n';
                break;
            }

            for(int dir=0;dir<8;++dir)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx<0 || nx > l || ny<0 || ny > l) continue;
                if(visited[nx][ny] == true) continue;

                q.emplace(nx,ny,distance+1);
                visited[nx][ny] = true;
            }
        }
    }
}