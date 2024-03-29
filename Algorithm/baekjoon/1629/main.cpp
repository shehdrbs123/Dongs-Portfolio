#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll num,divide;

ll recursive(ll count)
{
    if(count == 1)
        return num%divide;
    
    ll val = recursive(count/2);
    
    val = val * val % divide;

    if(count%2 != 0)
        return val * num % divide;
    return val;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll count;
    cin >> num >> count >> divide;
    ll result = recursive(count);
    cout << result;
}
