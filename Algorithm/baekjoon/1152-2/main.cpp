#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void split(const string& str, const char delimeter, vector<string>& v)
{
    istringstream iss(str);
    string buffer;
    while(getline(iss,buffer,delimeter))
    {
        v.emplace_back(buffer);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v{};
    string str;

    getline(cin,str);
    
    if(str[0] == ' ')
        str = str.erase(0,1);
    

    split(str,' ',v);

    cout << v.size();
    
}