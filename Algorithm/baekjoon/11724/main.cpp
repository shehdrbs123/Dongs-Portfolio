//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int root[1002];

int FindRoot(int i);
void Union(int i, int j);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int vertex=0, edge =0;
    
    set<int> collect{};
    cin >> vertex >> edge;
    
    
    for(int i=1;i<=vertex;++i)
    {
        root[i] = i;
    }
    
    for(int i=0;i<edge;++i)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        
        Union(vertex1, vertex2);
    }
    
    for(int i=1;i<=vertex;++i)
    {
        int x = FindRoot(i);
        collect.emplace(x);
    }
    
    cout << collect.size();
}

int FindRoot(int i)
{
    if(i == root[i])
        return i;
    root[i] = FindRoot(root[i]);
    return root[i];
}

void Union(int i, int j)
{
    int rooti = FindRoot(i);
    int rootj = FindRoot(j);
    
    if(rooti == rootj)
        return;
    
    if(rooti < rootj)
        root[j] = rooti;
    else 
        root[i] = rootj;
}
// 이렇게 풀수 없는 이유
// 모든 연결에 대해서 유지되는 것이 아님
// 중간 노드가 자신을 가리키는 노드를 알고 있지 않기 때문에
// 가리키는 노드들도 같이 루트를 바꾸어 주어야되는데 바꾸어 줄 수 없음.
// 그래서 유니온 파인드는 불가함.

