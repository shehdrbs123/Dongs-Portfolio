#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count;
    int value=1;
    cin >> count;
    
    for(int i=2;i<=count;++i)
    {
        value *= i;
    }
    
    cout << value;
}