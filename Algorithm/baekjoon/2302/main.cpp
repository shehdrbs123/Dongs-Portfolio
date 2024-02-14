#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    
    cin >> N;
    cin >> M;
    
    vector<int> v(N+1);
    unordered_set<int> fix{};
    
    for(int i=0;i<=N;++i)
    {
        v[i]=i;
    }
    
    for(int i=0;i<M;++i)
    {
        int num;
        cin >> num;
        fix.emplace(num);
    }
    int count =0;
    do
    {
        bool isRight = true;
        for(int i=1;i<=N;++i)
        {
            auto f = fix.find(i);
            if(f != fix.end())
            {
                if(v[i] != i)
                {
                    isRight = false;
                    break;
                }
                else
                {
                    continue;
                }
            }
                
            if(i-1 > v[i] || v[i] > i+1 )
            {
                isRight = false;
                break;
            }
        }
        if(isRight)
        {
            ++count;
        }
    }while(next_permutation(++v.begin(), v.end()));
    cout << count;
    
}