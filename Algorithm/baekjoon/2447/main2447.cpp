
#include <iostream>
#include <cmath>
using namespace std;

int N;
char field[6561][6561];

void recursive(int n,int startX,int startY)
{
    cout << n << '\n';
    if(n==1)
    {
        for(int i=startY;i<startY+3;++i)
        {
            for (int j=startX; j<startX+3; ++j)
            {
                field[i][j] = '*';
            }
        }
        field[startY+1][startX+1]=' ';
        return;
    }

    int end = pow(3,n);
    int gap = pow(3,n-1);
    int count = 0;
    for(int i=startY; i<startY+end; i+=gap)
    {
        for (int j=startX; j<startX+end; j+=gap)
        {
            if(++count == 4) continue;
            recursive(n-1,j,i);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int sqr = N;
    int count = 0;
    while(sqr > 1)
    {
        sqr /= 3;
        ++count;
    }
     
    recursive(count,0,0);

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << field[i][j];
        }
        cout << '\n';
    }
}
