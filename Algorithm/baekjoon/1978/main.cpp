#include <iostream>
#include <cmath>
using namespace std;

//제곱근까지 계산하기
bool isPrime(int number)
{
    float sqrtV = sqrt(number);
    if(number <= 1) return false;

    for(int i=2;i<=sqrtV;++i)
    {
        if(number%i == 0) { return false; }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count;
    int number;
    int result=0;
    cin >> count;
    
    for(int i=0;i<count;++i)
    {
        cin >> number;
        if(isPrime(number))
        {
            result += 1;
        }
    }
    cout << result;
}