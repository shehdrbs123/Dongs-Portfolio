#include <iostream>
#include <cmath>


void nQueen(int* pData, int nLength, int y, int* ans);
bool isProving(const int* pData, int y);

using namespace std;
int main()
{
    int n_Count{};
    int* queenList{};
    int result{};
    cin >> n_Count;
    queenList = new int[n_Count] {};

    nQueen(queenList, n_Count, 0, &result);
    
    printf("%d", result);

    delete [] queenList;
}

void nQueen(int* pData, int nLength, int y, int * pResult)
{
    if (y >= nLength)
    {
        (*pResult)++;
        return;
    }

    for (int row = 0; row < nLength; row++)
    {
        pData[y] = row;
        if (isProving(pData, y))
            nQueen(pData, nLength, y+1, pResult);
    }
}

bool isProving(const int* pData, int y)
{
    for (int y1 = y - 1; y1 >= 0; y1--) 
    {
        if (pData[y1] == pData[y] || abs(pData[y1] - pData[y]) == abs(y1 - y))
            return false;
    }
    return true;
}