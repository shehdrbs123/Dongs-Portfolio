#include <iostream>

using namespace std;

// 동적계획법을 이용한 표준 풀이방법

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