#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str, stringBuffer;
    cin >> str;
    
    istringstream ss(str);
    
    int C=0,A=0;
    while(getline(ss,stringBuffer,'|'))
    {
        char f = stringBuffer[0];
        if(f == 'A' || f == 'D' || f == 'E')
            ++A;
        else if(f == 'C' || f == 'F' || f == 'G')
            ++C;
    }
    
    if(C<A)
        cout << "A-minor";
    else if(C>A)
        cout << "C-major";
    else
    {
        char f = str[str.size()-1];
        if(f == 'A' || f == 'D' || f == 'E')
            cout << "A-minor";
        else if(f == 'C' || f == 'F' || f == 'G')
            cout << "C-major";
    }
        
}