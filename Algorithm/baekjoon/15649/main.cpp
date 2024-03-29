#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
bool used[10];
int number[10];

void func(int k)
{
    if(k==M)
    {
        for(int i=0;i<M;++i)
        {
           cout << number[i] << " ";
        }
        cout << '\n';
    }
    
    for(int i=1;i<=N;++i)
    {
        if(!used[i])
        {
            used[i] = true;
            number[k] = i;
            func(k+1);
            used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    func(0);
    
}