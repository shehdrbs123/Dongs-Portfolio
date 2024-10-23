#include <iostream>
#include <list>

using namespace std;

int N,K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    list<int> l{};
    
    for(int i=1;i<=N;++i)
    {
        l.push_back(i);
    }
    
    int size = N;
    cout << '<';
    int idx = 0;
    for(int i=0;i<size-1;++i)
    {
        idx += K-1;
        idx %= (size-i);
        auto itr = l.begin();
        advance(itr,idx);
        cout << *itr<< ", ";
        l.erase(itr);
    }
    cout << *(l.begin()) << '>';
}