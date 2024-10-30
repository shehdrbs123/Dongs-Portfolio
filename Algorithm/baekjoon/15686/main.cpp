#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int board[51][51];
bool visited[51][51];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    vector<pair<int,int>> homeList{};
    vector<int> result{};
    int resultSum=0;
    homeList.reserve(14);
    result.reserve(14);
    
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin >> board[i][j];
            if(board[i][j] == 1)
            {
                homeList.emplace_back(i,j);
            }
        }
    }
    
    for(int i=0;i<homeList.size();++i)
    {
        auto chick = homeList[i];
        queue<tuple<int,int,int>> q{};
        bool isComplete=false;
        q.emplace(chick.second,chick.first,0);

        visited[chick.second][chick.first] = true;

        while(!q.empty() && !isComplete)
        {
            int x,y,len;
            tie(x,y,len) = q.front();
            q.pop();
            for(int dir=0; dir<4;++dir)
            {
                int nx = x+dx[dir];
                int ny = y+dy[dir];
                
                if(nx<0 || nx >=N || ny <0 || ny >=N) continue;
                if(visited[ny][nx]) continue;    
                if(board[ny][nx] == 2)
                {
                    result.emplace_back(len+1);
                    isComplete = true;
                    break;
                }
                q.emplace(nx,ny,len+1);
                visited[ny][nx]=true;
            }
        }

        for(int i=0;i<N;++i)
        {
            memset(visited[i],0,N);
        }
    }
    
    sort(result.begin(),result.end());
    

    for(int i=0;i<M;++i)
    {
        resultSum += result[i];
    }
    cout << resultSum;
}