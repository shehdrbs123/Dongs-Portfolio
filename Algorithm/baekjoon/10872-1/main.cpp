#include <iostream>

using namespace std;
//일반 재귀
int fact(int f)
{
    if(f == 1)
        return f;
    return f * fact(f-1);
}

//꼬리 재귀
int tailFact(int f, int result)
{
    if(f == 1)
        return result;
    return tailFact(f-1,result * f);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count;
    int result = 1;
    cin >> count;
    
    cout << tailFact(count,result);
}