#include <bits/stdc++.h>

using namespace std;

int N, K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unordered_map<int,int> m{};
    
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        int num;
        cin >> num;
            
        auto itr = m.find(num);
        if(itr != m.end())
        {
            ++(itr->second);
        }
        else
        {
            m.emplace(num,1);
        }
    }
    
    cin >> K;
    for(int i=0;i<K;++i)
    {
        int num;
        cin >> num;
        auto itr = m.find(num);
        if(itr != m.end())
        {
            cout << itr->second<< " ";
        }
        else
        {
            cout << "0 ";
        }
    }
}