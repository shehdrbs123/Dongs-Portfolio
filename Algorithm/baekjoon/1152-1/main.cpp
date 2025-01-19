#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int count = 0;
    int start = 0, end;
    
    getline(cin,str);

    end = str.length();
    if(str[start] == ' ')
        ++start;
    
    if(str[end-1] == ' ')
        --end;

    if(start >= end)
    {
        cout << '0';
        return 0;
    }    

    for(int i=start;i<end;++i)
    {
        if(str[i] == ' ')
            ++count;
    }

    cout << count+1;
}