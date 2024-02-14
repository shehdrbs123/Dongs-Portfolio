#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int M,N;
    
    cin >> M >> N;
    
    for(int i=M; i<=N; ++i)
    {
        int targetNum = sqrt(i);
        int divideCount = 0;
        for(int j=1;j<=targetNum;++j)
        {
            if(i%j == 0)
            {
                ++divideCount;
                if(j != i/j)
                    ++divideCount;
            }
            if(divideCount > 2)
                break;
        }
        if(divideCount == 2)
            cout << i << '\n';
    }
}