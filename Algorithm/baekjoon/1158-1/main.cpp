#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    
    cin >> N >> K;
    list<int> l;
    
    for(int i=0;i<N;++i)
    {
        l.push_back(i+1);
    }
    auto itr = l.begin();
    
    cout << "<";
    while(l.size() > 1)
    {
        for(int i=1;i<K;++i) 
        {
            ++itr;
            if(itr == l.end())
                itr = l.begin();
        }
            
        cout << *itr << ", ";
        itr++;
        if(itr == l.end())
        {
            itr--;
            l.erase(itr);
            itr = l.begin();
        }else
        {
            itr--;
            itr = l.erase(itr);
        }
    }

    cout << *(l.begin()) << ">";
}