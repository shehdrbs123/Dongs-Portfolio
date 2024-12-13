#include <iostream>
#include <vector>
#include <tuple>


using namespace std;

int room[9][9];
int check[9][9];
int x,y;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int result;

int checkLine(int dir, int sx,int sy,int fill)
{
    int shapCount = 0;
    if(dir%2 == 0)
    {
        for(int i=sy; 0<=i && i<y;i += dy[dir])
        {
            if(room[i][sx] == 6)
                break;
                        
            check[i][sx] = fill;
        }
    }else
    {
        for(int j=sx; 0<=j && j<x; j += dx[dir])
        {
            if(room[sy][j] == 6)
                break;
            
            check[sy][j] = fill;    
        
        }
    }

    
    return shapCount;
}

void dfs(vector<tuple<int,int,int>>& v, int index, int shapCount)
{
    if(index == v.size())
    {
        int count=0;
        for(int i=0;i<y;++i)
        {
            for(int j=0;j<x;++j)
            {
                if(check[i][j] == 7)
                {
                    ++count;
                }
            }
        }
        if(result < count)
            result = count;
        
        return;
    }
    int num, sx, sy;
    int count = 0;
    tie(num,sx,sy) = v[index];
    switch(num)
    {
        case 1:
            for(int dir=0;dir<4;++dir)
            {
                count = checkLine(dir,sx,sy,7);
                dfs(v,index+1,shapCount+count);
                checkLine(dir,sx,sy,0);
            }
            break;
        case 2:
            count = checkLine(0,sx,sy,7);
            count+=checkLine(2,sx,sy,7);
            dfs(v,index+1,shapCount+count);
            checkLine(0,sx,sy,0);
            checkLine(2,sx,sy,0);
            
            count = checkLine(1,sx,sy,7);
            count+=checkLine(3,sx,sy,7);
            dfs(v,index+1,shapCount+count);
            checkLine(1,sx,sy,0);
            checkLine(3,sx,sy,0);
            
            break;
        case 3:
            for(int dir=0;dir<4;++dir)
            {
                count = checkLine(dir,sx,sy,7);
                count += checkLine((dir+1)%4,sx,sy,7);
                dfs(v,index+1,shapCount+count);
                checkLine(dir,sx,sy,0);
                checkLine((dir+1)%4,sx,sy,0);
            }
            break;
        case 4:
            for(int dir=0;dir<4;++dir)
            {
                count = checkLine(dir,sx,sy,7);
                count += checkLine((dir+1)%4,sx,sy,7);
                count += checkLine((dir+2)%4,sx,sy,7);
                dfs(v,index+1,shapCount+count);
                checkLine(dir,sx,sy,0);
                checkLine((dir+1)%4,sx,sy,0);
                checkLine((dir+2)%4,sx,sy,0);
            }
            break;
        case 5:
            count = checkLine(0,sx,sy,7);
            count += checkLine(1,sx,sy,7);
            count += checkLine(2,sx,sy,7);
            count += checkLine(3,sx,sy,7);
            dfs(v,index+1,shapCount+count);
            checkLine(0,sx,sy,0);
            checkLine(1,sx,sy,0);
            checkLine(2,sx,sy,0);
            checkLine(3,sx,sy,0);
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> y >> x;
    int no = 0;
    vector<tuple<int,int,int>> v{};
    for(int i=0;i<y;++i)
    {
        for(int j=0;j<x;++j)
        {
            int num;
            cin >> num;
            
            if(0<num && num < 6)
                v.emplace_back(num,j,i);
            if(num == 6)
                ++no;
            room[i][j] = num;
        }
    }
    
    dfs(v,0,0);
    cout << x*y << " " << no << " " << result;
    cout << x*y-no-result;
    
}