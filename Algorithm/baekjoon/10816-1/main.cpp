#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[20000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        int num;
        cin >> num;
        ++A[num+10000000];
    }

    cin >> K;

    for(int i=0;i<K;++i)
    {
        int num;
        cin >> num;
        cout << A[num+10000000] << " ";
    }
}