#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N,M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    vector<int> v{};

    unordered_map<int, int> m{};
    
    v.reserve(N);
    for(int i=0;i<M;++i)
    {
        int f, s;
        cin >> f >> s;
        auto fItr = m.find(f);
        auto sItr = m.find(s);
        
        if(fItr != m.end())
        {
            if(sItr != m.end())
            {
                if(fItr->second>sItr->second)
                {
                    v.erase(v.begin()+fItr->second);                
                    v.insert(v.begin()+sItr->second,f);
                    fItr->second = sItr->second;
                    ++(sItr->second);
                }
            }else
            {
                v.insert(v.begin()+(fItr->second+1),s);
                m.emplace(s,fItr->second+1);
            }
        }
        else
        {
            if(sItr != m.end())
            {
                v.insert(v.begin()+sItr->second,f);
                m.emplace(f,sItr->second);
                ++(sItr->second);
            }
            else    
            {
                v.push_back(f);
                m.emplace(f,v.size()-1);
                v.push_back(s);
                m.emplace(s,v.size()-1);
            }
        }
    }


    for(int i=0;i<N;++i)
    {
        cout << v[i] << ' ';
    }
}