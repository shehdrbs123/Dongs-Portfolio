#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,v;
    int result = 0;
    cin >> a >> b >> v;

    v-=a;

    result = ceil(v/(double)(a-b));
    cout << result + 1;

}