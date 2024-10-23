#include <iostream>
#include <list>
#include <string>

using namespace std;

int N;
string intStr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> intStr;
    int size = intStr.length();
    list<char> l;
    for(int i=0;i<size;++i)
    {
        l.push_back(intStr[i]);
    }
    auto itr = l.end();
    
    cin >> N;
    cin.ignore();
    for(int i=0;i<N;++i)
    {
        getline(cin,intStr);
        char order = intStr[0];
        switch(order)
        {
            case 'P' :
                l.insert(itr,intStr[2]);
                break;
            case 'L' :
                if(itr != l.begin())
                    --itr;
                break;
            case 'D' :
                 if(itr != l.end())
                    --itr;
                break;
            case 'B':
                if(itr != l.begin())
                {
                    auto itr2 = itr;
                    itr2--;
                    l.erase(itr2);
                }
                break;
        }
    }

    for(auto c : l)
    {
        cout << c;
    }
}
