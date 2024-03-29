#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;

struct compare
{
    bool operator()(const string& a, const string & b) const
    {
        int aSize = a.size();
        int bSize = b.size();
        if(aSize != bSize)
        {
            return aSize < bSize;
        }
        int aNum=0,bNum=0;
        for(int i=0;i<aSize;++i)
        {
            if('0' <= a[i] && a[i] <= '9')
            {
                aNum += a[i] - '0';
            }
        }
        
        for(int i=0;i<bSize;++i)
        {
            if('0' <= b[i] && b[i] <= '9')
            {
                bNum += b[i] - '0';
            }
        }
        
        if(aNum != bNum)
        {
            return aNum < bNum;
        }
        
        return a<b;
        
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<string,compare> s;
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        string str;
        cin >>str;
        
        s.emplace(str);
    }
    
    for(auto itr = s.begin();itr != s.end();++itr)
    {
        cout << *itr << '\n';
    }
    
}