#include <iostream>

using namespace std;

int N;
int K;
int coin[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    for(int i=0;i<N;++i)
    {
        cin >> coin[i];
    }
    int rest = K;
    int result = 0;
    for(int i=N-1;i>=0;--i)
    {
        if(coin[i] > rest)
            continue;
        result += rest/coin[i];
        rest %= coin[i];
        
        if(rest == 0)
            break;
    }
    
    cout << result;
}