#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string,int>& a, const pair<string,int>& b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    unordered_map<string,int> m{};
    m["Bessie"] = 0;
    m["Elsie"] = 0; 
    m["Daisy"] = 0;
    m["Gertie"] = 0;
    m["Annabelle"] = 0;
    m["Maggie"] = 0;
    m["Henrietta"] = 0;
    
    for(int i=0;i<num;++i)
    {
        string name;
        int count;
        cin >> name >> count;
        
        auto itr = m.find(name);
        itr->second += count;
    }

    vector<pair<string,int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(),compare);

    int smallest = v[0].second;
    for(int i=0;i<v.size();++i)
    {
        if(smallest < v[i].second)
        {
            if(i+1 < v.size())
            {
                if(v[i].second != v[i+1].second)
                    cout << v[i].first << '\n';
                else
                    cout << "Tie\n";
            }
            else
            {
                cout << v[i].first << '\n';
            }
            return 0;
        }
    }
    cout << "Tie\n"; 
    
}