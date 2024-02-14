#include <bits/stdc++.h>

using namespace std;

int board[27][27]{};
bool visited[27][27]{};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int line{};
    vector<int> apartments{};
    queue<pair<int,int>> q{};
    cin >> line; 
    
    for(int i=1;i<=line;++i)
    {
        string tmpStr{};
        cin >> tmpStr;
        for(int j=0;j<line;++j)
        {
            board[i][j+1] = tmpStr[j]-'0';
        }
    }
    
    
    for(int i=1;i<=line;++i)
    {
        for(int j=1;j<=line;++j)
        {
            int count{};
            if(board[i][j] != 0 && visited[i][j] != true)
            {
                visited[i][j] = true;
                q.emplace(i,j);
                ++count;
            }
            
            while(!q.empty())
            {
                pair<int,int> pos = q.front(); q.pop();
                
                for(int dir = 0; dir<4;++dir)
                {
                    int nx = pos.first + dx[dir];
                    int ny = pos.second + dy[dir];
                    
                    if(board[nx][ny] == 0 || visited[nx][ny]) continue;
                    
                    q.emplace(nx,ny);
                    visited[nx][ny] = true;
                    ++count;
                }
            }
            if(count > 0)
                apartments.emplace_back(count);
        }
    }
    
    
    sort(apartments.begin(),apartments.end());
    
    cout << apartments.size() << '\n';
    for(int count : apartments)
    {
        cout << count << '\n';
    }
}
