#include <bits/stdc++.h>

using namespace std;

int z,y,x;

int dx[] = {0,1,0,-1,0,0};
int dy[] = {1,0,-1,0,0,0};
int dz[] = {0,0,0,0,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true)
    {
        cin >> z >> y >> x;
        
        if(z==0 && y==0 && x==0)
            break;
        string m[31][31];
        bool visited[31][31][31] = {0,};
        int sx,sy,sz;
        bool isCanStart = false;
        

        for(int i=0;i<z;++i)
        {
            for(int j=0;j<y;++j)
            {
                cin >> m[i][j];
                for(int k=0;k<x;++k)
                {
                    if( m[i][j][k] == 'S' )
                    {
                        isCanStart = true;
                        sx = k;
                        sy = j;
                        sz = i;
                    }
                }
            }
        }

        if(!isCanStart)
            cout << "Trapped!" <<'\n';
        
        queue<tuple<int,int,int,int>> q{};
        
        q.emplace(sx,sy,sz,0);
        visited[sz][sy][sx] = true;
        
        bool isEscape = false;

        while(!q.empty())
        {
            auto pos = q.front();q.pop();
            
            for(int dir = 0; dir<6;++dir)
            {
                int tx,ty,tz,time;
                tie(tx,ty,tz,time) = pos;
                tx += dx[dir];
                ty += dy[dir];
                tz += dz[dir];
                time += 1;
                
                if(tx<0 || tx>= x || ty<0 || ty>=y || tz<0 || tz>=z ) continue;
                if(visited[tz][ty][tx]) continue;
                if(m[tz][ty][tx] == '#') continue;
                if(m[tz][ty][tx] == 'E') 
                {
                    isEscape = true;
                    cout << "Escaped in " << time << " minute(s).\n";
                    break;
                }
                    
                q.emplace(tx,ty,tz,time);
                visited[tz][ty][tx] = true;
            
            }
            
            if(isEscape) break;

        }
        
        if(!isEscape)
        {
            cout << "Trapped!" <<'\n';
        }
    }
}