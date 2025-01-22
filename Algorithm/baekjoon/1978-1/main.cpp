#include <iostream>

using namespace std;

bool isNotPrime[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    isNotPrime[1] = true;
    for(int i=2;i<=1000;++i)
    {
        int duple = 1000/i;
        for(int j=2;j<=duple;j++)
        {
            isNotPrime[i*j] = true;
        }
    }

    int count;
    int number;
    int result = 0;
    cin >> count;

    for(int i=0;i<count;++i)
    {
        cin >> number;
        if(!isNotPrime[number])
            result += 1;
    }

    cout << result;

}