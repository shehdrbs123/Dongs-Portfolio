#include <iostream>
#include <queue>

using namespace std;

int N;
int result = 0;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void move(vector<vector<int>>& field, int dir)
{
    int s=0,e=N;
    int d=1;

    if(dir<2)
    {
        s = N-1;
        e = -1;
        d = -1;
    }
    
    for(int i=s;i!=e;i+=d)
    {
        for(int j=s;j!=e;j+=d)
        {
            if(field[i][j] == 0) continue;
            
            int x = i;
            int y = j;
            while(true)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx<0 || nx>=N || ny <0 || ny>=N) break;
                if(field[nx][ny] != 0 ) break;
                
                field[nx][ny] = field[x][y];
                field[x][y] = 0;
                x = nx;
                y = ny;
            }
        }
    }
}

void sum(vector<vector<int>>& field, int dir)
{
    int s=0,e=N;
    int d=1;

    if(dir>=2)
    {
        s = N-1;
        e = -1;
        d = -1;
    }

    
    for(int i=s;i!=e;i+=d)
    {
        for(int j=s;j!=e;j+=d)
        {
            if(field[i][j] == 0) continue;
            
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx<0 || nx>=N || ny <0 || ny>=N) break;

            if(field[i][j] == field[nx][ny])
            {
                field[nx][ny] += field[i][j];
                field[i][j] = 0;
                result = max(result,field[nx][ny]);
            }
        }
    }
}

void print(vector<vector<int>>& field)
{
    for (size_t i = 0; i < field.size(); i++)
    {
        /* code */
        for (size_t j = 0; j < field[0].size(); j++)
        {
            /* code */
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    vector<vector<int>> field(N);
    for(int i=0;i<N;++i)
    {
        field[i].resize(N);
        for(int j=0;j<N;++j)
        {
            cin >> field[i][j];
        }
    }

    // 방향, 횟수
    queue<pair<vector<vector<int>>,int>> q;
    q.emplace(field,0);
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();
        int count = pos.second+1;

        for(int dir=0;dir<4;++dir)
        {
            auto f = pos.first;
            move(f, dir);
            sum(f, dir);
            move(f, dir);
            cout << endl;
            print(f);
            cout << endl;
            if(count < 1)
            {
                q.emplace(f,count);
            }
        }
    }
    
    cout << result;
} 
