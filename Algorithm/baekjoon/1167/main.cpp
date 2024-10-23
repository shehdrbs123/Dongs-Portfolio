#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
long long Max;
void DFS(vector<vector<pair<int,int>>>& v, vector<bool>& visited,int idx, long long length)
{
    auto node = v[idx];
    
    if(Max < length)
    {
        Max = length;
    }

    for(int i=0;i<node.size();++i)
    {
        int nextNode = node[i].first;
        int curLength = node[i].second;

        if(!visited[nextNode])
        {
            visited[nextNode] = true;
            DFS(v,visited,nextNode,length+curLength);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    vector<vector<pair<int,int>>> v(N+1);
    vector<bool> visited(N+1);
    int startNode=N;
    for(int i=1;i<=N;++i)
    {
        int num;
        cin >> num;

        int other;
        int nodeCount=0;
        while(true)
        {
            cin >> other;
            if(other == -1)
                break;
            
            nodeCount++;
            int length;
            cin >> length;

            v[num].emplace_back(other,length);
        }
        if(nodeCount==1 && startNode > i)
            startNode = i;
            
    }
    cout << startNode << '\n';
    visited[startNode] = true;
    DFS(v,visited,startNode,0);
    
    cout << Max;
}
