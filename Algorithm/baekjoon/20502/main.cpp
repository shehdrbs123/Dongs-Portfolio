#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct article
{
    int rank;
    set<int> keywords;
};

bool compare(const pair<article*,int> & article1, const pair<article*,int>article2)
{
    return article1.first->rank < article2.first->rank;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    vector<article> v(N);

    for(int i=0;i<N;++i)
    {
        cin >> v[i].rank;
    }
    
    for(int i=0;i<N;++i)
    {
        int k;
        cin >> k;
        for(int j=0;j<k;++j)
        {
            int keyword;
            cin >> keyword;
            v[i].keywords.emplace(keyword);
        }
    }

    int queryCount;
    cin >> queryCount;

    for(int i=0;i<queryCount;++i)
    {
        int query;
        cin >> query;

        vector<pair<article*,int>> q;
        for(int i=0;i<v.size();++i)
        {
            auto itr = v[i].keywords.find(query);
            if(itr != v[i].keywords.end())
            {
                q.emplace_back(&v[i],i+1);
            }
        }
        if(q.size() == 0)
        {
            cout << -1 << '\n';
            continue;
        }

        sort(q.begin(),q.end(),compare);

        for(int i=0;i<q.size();++i)
        {
            cout << q[i].second << ' ';
        }
        cout << '\n';
    }
    
}