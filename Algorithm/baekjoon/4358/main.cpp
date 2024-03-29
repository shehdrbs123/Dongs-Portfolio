#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string,int> m{};
    int treeCount=0;
    
    while(true){
        string tmp;
        getline(cin,tmp,'\n');
        if(cin.eof()) break;
        
        auto d = m.find(tmp);
        if(d != m.end())
            d->second +=1;
        else
        {
             m.emplace(tmp,1);   
        }
        ++treeCount;
    }
    
    cout << fixed;
    cout.precision(4);
    for(auto a : m)
    {
        cout << a.first << " ";
        cout << a.second/(float)treeCount* 100<< '\n';
    }
    
}