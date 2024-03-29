#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string input;

bool GetPelindrom(int sz, int l, int r, int& count)
{
    bool isPelindrom=true;
    for(;;--l,++r)
    {
        if(l<0)
        {
            count += (sz-r)*2;
            break;
        }else if(r>=sz)
        {
            count += (l+1)*2; 
            break;
        }
        if(input[l] != input[r]) 
        {
            isPelindrom = false;
            break;
        }
        count += 2;
    }
    return isPelindrom;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        
    cin >> input;
    int minValue = 1000;
    int sz = input.size();
    if(sz == 0)
    {
        cout << 0;
        return 0;
    }
        
    for(int i=0;i<sz;++i)
    {
        int count=0;
        bool isPelindrom = GetPelindrom(sz,i,i+1,count);
        
        if(isPelindrom)
            minValue = min(minValue, count);
        cout << minValue << '\n';

        count = 1;
        isPelindrom = GetPelindrom(sz,i-1,i+1,count);
        if(isPelindrom)
            minValue = min(minValue, count);
        cout << minValue << '\n';

    }

    cout << minValue;
}
