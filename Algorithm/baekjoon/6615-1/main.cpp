#include <bits/stdc++.h>

using namespace std;

void calList(vector<long long>& v,int num)
{
    long long temp = num;
    v.push_back(num);
    while(temp != 1)
    {
        if(temp %2 == 0) temp /=2;
        else temp = 3*temp +1;
        
        v.push_back(temp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true)
    {
        int a,b;
        cin >> a >> b;
        
        if(a==0) break;
        
        vector<long long> va{};
        vector<long long> vb{};
        
        calList(va,a);
        calList(vb,b);

        int aSize = va.size();
        int bSize = vb.size();
        int size = aSize;
        int i = 1;
        if(size > bSize) size = bSize;
        
        for(;i<=size;++i)
        {
            if(va[aSize-i] != vb[bSize-i])
            {
                break;
            }
        }
        i-=1;
        
        cout << a <<" needs " << aSize-i << " steps, "
            << b <<" needs " << bSize-i<<" steps, they meet at " << vb[bSize-i] << '\n';

    }
}