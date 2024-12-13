#include <iostream>
#include <cmath>

using namespace std;

int man[7];
int woman[7];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num, k, result =0;
    
    cin >> num >> k;
    
    
    for(int i=0;i<num;++i)
    {
        int gender, grade;
        cin >> gender >> grade;
        if(gender == 0)
            ++woman[grade];
        else
            ++man[grade];
        
    }
    
    for(int i=1;i<=6;++i)
    {
        int wCount=0, mCount=0;
        wCount = ceil(woman[i]/(float)k);
        mCount = ceil(man[i]/(float)k);
        result += wCount + mCount;
    }

    cout << result;
}