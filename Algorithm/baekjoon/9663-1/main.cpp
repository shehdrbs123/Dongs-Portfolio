#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int s=0;
int result=0;
vector<pair<int,int>> nqueen;

void print()
{
    for(int i=0;i<nqueen.size();++i)
    {
        cout << nqueen[i].first << " " << nqueen[i].second << '\n';
    }
    cout << '\n';
}

void nqueen_dfs(int x,int y)
{
    
    //print();
    for(int i=0;i<nqueen.size();++i)
    {
        auto pos = nqueen[i];
        if(pos.first == x) return;

        int xgap = abs(pos.first - x);
        int ygap = abs(pos.second- y);

        if(xgap == ygap) return;
    }

    if(y+1 >= s)
    {
        result += 1;
        return;
    }
    
    nqueen.emplace_back(x,y);
    
    for(int i=0;i<s;++i)
    {
        if(i==x) continue;
        nqueen_dfs(i,y+1);
    }
    nqueen.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    nqueen.reserve(s);
    for(int x=0;x<s;++x)
    {
        nqueen_dfs(x,0);
    }

    cout << result;
    
}