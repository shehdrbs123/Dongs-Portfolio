//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int input;
    
    cin >> input;


    for(int i = input/5;i>=0;--i)
    {
        int rest = input - (5*i);
        
        int packed = i;
        if(rest != 0)
        {
            int threeRest = rest % 3;
            if(threeRest > 0)
                continue;
            
            cout << i + (int) rest/3;
            return 0;
        }
        else
        {
            cout << i;
            return 0 ;
        }

    }

    cout << -1;    
}