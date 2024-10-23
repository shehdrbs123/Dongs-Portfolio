#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[51];
int b[51];

//재배열 부등식
// 큰원소 * 큰원소 => 최대
// 큰원소 * 작은원소 => 최소
// 라는 증명의 부등식
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        cin >> a[i];
    }
    
    for(int i=0;i<N;++i)
    {
        cin >> b[i];
    }
    
    sort(a,a+N,greater<int>());
    sort(b,b+N);
    int result = 0;
    for(int i=0;i<N;++i)
    {
        result += a[i]*b[i];
    }

    cout << result;
}