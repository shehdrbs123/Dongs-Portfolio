#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int y,x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> y >> x;
    
    vector<vector<int>> m(y,vector<int>(x));
    vector<vector<bool>> visited(y,vector<bool>(x,false));
    list<tuple<int,int,int>> ocean{};
    int resultYear = 0;
    
    for(int i=0;i<y;++i)
    {
        for(int j=0;j<x;++j)
        {
            cin >> m[i][j];
            if(m[i][j] > 0) ocean.emplace_back(j,i,m[i][j]);
        }
    }
    while(true)
    {
        resultYear+=1;
        //빙하 녹이기
        for(auto itr = ocean.begin(); itr != ocean.end();++itr)
        {
            int zeroCount=0;
            int sx,sy,sz;
            tie(sx,sy,sz) = *itr;
            
            for(int dir=0;dir<4;++dir)
            {
                int ex = sx + dx[dir];
                int ey = sy + dy[dir];
                
                if(ex<0 || ex>= x || ey<0 || ey >=y) continue;
                if(m[ey][ex] == 0) ++zeroCount;
            }
            
            sz -= zeroCount;
            get<2>(*itr) = sz > 0 ? sz : 0;
        }
        //녹은 빙하 반영
        for(auto itr = ocean.begin(); itr != ocean.end();++itr)
        {
            int sx,sy,num;
            tie(sx,sy,num) = *itr;
            
            m[sy][sx] = num;
            if(num == 0)
            {
                itr = ocean.erase(itr);
                --itr;
            }
        }

        if(ocean.size() == 0)
        {
            cout << 0;
            break;
        }
                
        int worldCount = 0;
        // 빙하 개수 세기
        for(auto itr = ocean.begin(); itr != ocean.end();++itr)
        {
            int sx,sy,num;
            tie(sx,sy,num) = *itr;
            if(visited[sy][sx]) continue;
            
            ++worldCount;
            
            queue<pair<int,int>> q{};

            q.emplace(sx,sy);
            visited[sy][sx] = true;

            while(!q.empty())
            {
                auto pos = q.front(); q.pop();
                for(int dir=0;dir<4;++dir)
                {
                    int ex = pos.first + dx[dir];
                    int ey = pos.second + dy[dir];
                
                    if(ex<0 || ex>= x || ey<0 || ey >=y) continue;
                    if(visited[ey][ex]) continue;
                    if(m[ey][ex] == 0) continue;
                    
                    q.emplace(ex,ey);
                    visited[ey][ex] = true;
                }         
            }
        }

        // 방문 초기화
        for(auto itr = ocean.begin(); itr != ocean.end();++itr)
        {
            int sx,sy,num;
            tie(sx,sy,num) = *itr;
            visited[sy][sx] = false;
        }
        
        if(worldCount > 1)
        {
            cout << resultYear;
            break;
        }
    }
}