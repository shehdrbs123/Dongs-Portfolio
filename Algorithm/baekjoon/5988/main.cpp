#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    cin.ignore();
    for(int i=0;i<num;++i)
    {
        string digit{};
        int digitSize{};
        char lastNum{};
        
        getline(cin,digit);
        
        digitSize = digit.length();
        lastNum = digit[digitSize-1]-'0';
        
        if(lastNum%2 == 0)
            cout << "even\n";
        else 
            cout << "odd\n";
    }
}