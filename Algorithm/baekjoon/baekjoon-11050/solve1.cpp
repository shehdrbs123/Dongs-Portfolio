#include <iostream>

using namespace std;

// 단순 이항 계수 공식 이용
long GetFactorial(int n);
int main()
{
    int n{};
    int k{};
    long solve{};

    cin >> n >> k;

    solve = GetFactorial(n) / GetFactorial(n-k) / GetFactorial(k);
    cout << solve;
}

long GetFactorial(int n)
{
    long solve = n;
    for(int i=1;i<n;i++)
    {   
        solve *= i;
    }
    return solve;
}