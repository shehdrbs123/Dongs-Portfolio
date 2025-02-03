#include <iostream>

using namespace std;

int numCount[10001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n=0;
    cin >> n;

    for(int i=0;i<n;++i)
    {
        int c=0;
        cin >> c;
        ++numCount[c];
    }

    for(int i=1;i<=10000;++i)
    {
        while(numCount[i] > 0)
        {
            cout << i << '\n'; 
            --numCount[i];
        }
    }
}