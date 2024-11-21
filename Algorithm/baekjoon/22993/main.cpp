#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> num;
    
    num -= 1;

    vector<unsigned long long> v(num);
    unsigned long long user;

    cin >> user;
    for(int i=0;i<num;++i)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    for(int i=0;i<num;++i)
    {
        if(user <= v[i])
        {
            cout << "No";
            return 0;
        }
        user += v[i];
    }
    cout << "Yes";
}