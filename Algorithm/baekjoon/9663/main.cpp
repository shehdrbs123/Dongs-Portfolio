#include <iostream>
#include <cmath>
using namespace std;

int N=0;
int result=0;
int board[15];

bool isProving(int row)
{
    for(int i = row-1; i >= 0; --i)
    {
        if(board[i] == board[row] || abs(row-i) == abs(board[row]-board[i]))
            return false;
          
    }
    return true;
}

void nqueen(int row)
{
    if(row == N)
    {
        ++result;
        return;
    }
    
    for(int i=0;i<N;++i)
    {
        board[row] = i;
        if(isProving(row))
        {
            nqueen(row+1);
        }
    }

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    nqueen(0);

    cout << result;
}
