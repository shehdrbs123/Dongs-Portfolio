#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <cstring>

using namespace std;

int N,M;
char field[9][9];
// 0 : down
// 1 : right
// 2 : up
// 3 : left;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int checkSpot = 0;
void print(const char check[][9])
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cout << check[i][j] << " ";
        }
        cout << '\n';
    }
}

void CheckLine(int i, int j,int dir, char check[][9])
{
    while(true)
    {  
        if(i<0 || i>=N || j<0 || j>=M) break;
        if(field[i][j] == '6')
            break;
        if(check[i][j] != '#') 
        {
            check[i][j] = '#';
            ++checkSpot;
        }
        i += dy[dir];
        j += dx[dir];
    }
}

void CheckTwoSide(int i,int j,int baseDir, char check[][9])
{
    CheckLine(i,j,baseDir,check);
    baseDir = (baseDir+2) % 4;
    CheckLine(i,j,baseDir,check);
}

void Move(int i,int j, int type,int baseDir, char check[][9])
{
    switch(type)
    {
        case 1 : 
            CheckLine(i,j,baseDir,check);
            break;
        case 2 :
            CheckTwoSide(i,j,baseDir,check);
            break;
        case 3 : 
            CheckLine(i,j,baseDir,check);
            baseDir = (baseDir+1) % 4;
            CheckLine(i,j,baseDir,check);
            break;
        case 4 :
            CheckLine(i,j,baseDir,check);
            baseDir = (baseDir+1) % 4;
            CheckTwoSide(i,j,baseDir,check);
            break;
        case 5 : 
            CheckTwoSide(i,j,baseDir,check);
            baseDir = (baseDir+1) % 4;
            CheckTwoSide(i,j,baseDir,check);
            break;
    }
}

// 0 : down
// 1 : right
// 2 : up
// 3 : left;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    vector<tuple<int,int,int>> cctv{};
    cctv.reserve(8);
    int fieldSize = N*M;
    int minValue=64;
    
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin >> field[i][j];

            if(field[i][j] != '0')
            {
                if(field[i][j] != '6')
                {
                    cctv.emplace_back(field[i][j]-'0',i,j);
                }else{
                    --fieldSize;
                }
                
            }      
        }
    }

    int a = pow(4,cctv.size());

    for(int i=0;i<a;++i)
    {
        int dir = i;
        char check[9][9];
        memset(check,'0',sizeof(check));
        for(int j=0;j<cctv.size();++j)
        {
            
            int cctvNum,y,x;
            tie(cctvNum, y, x) = cctv[j];
            Move(y,x,cctvNum,dir%4,check);
            dir /= 4;
        }

        int currentUnCheck = fieldSize - checkSpot;   
        if(minValue > currentUnCheck)
            minValue = currentUnCheck;
        checkSpot = 0;
    }

    cout << minValue;
    
}