#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,M;

vector<int>* D;
vector<pair<int,int>>* TREE;
pair<int,int> dump = pair<int,int>(1000000000,-1);

pair<int,int>* InitSegmentTree(int start, int end, int node)
{
    if(start == end)
    {
        (*TREE)[node].first = (*D)[start];
        (*TREE)[node].second = (*D)[start];
        return &((*TREE)[node]);
    }
    
    int mid = (start+end)/2;
    
    pair<int,int>* leftResult =  InitSegmentTree(start, mid, node*2);
    pair<int,int>* rightResult = InitSegmentTree(mid+1, end, node*2+1);
    
    (*TREE)[node].first = min(leftResult->first,rightResult->first);
    (*TREE)[node].second = max(leftResult->second,rightResult->second);
    return &((*TREE)[node]);
}


pair<int,int> GetMinMax(int start, int end, int node, int left, int right)
{
    if(left > end  || right < start) return dump;
    if(left <= start && end <= right) return (*TREE)[node];

    int mid = (start+end) /2;

    auto leftResult = GetMinMax(start,mid,node*2,left,right);
    auto rightResult  = GetMinMax(mid+1,end,node*2+1,left,right);

    pair<int,int> p;
    p.first = min(leftResult.first,rightResult.first);
    p.second = max(leftResult.second,rightResult.second);

    return p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    vector<int> d(N);
    vector<pair<int,int>> tree(N*4);
    
    D = &d;
    TREE = &tree;
    for(int i=0;i<N;++i)
    {
        cin >> d[i];
    }
    
    InitSegmentTree(0,N-1,1);
    
    for(int i=0;i<M;++i)
    {
        int s,e;
        cin >> s >> e;
        auto result = GetMinMax(0,N-1,1,s-1,e-1);
        cout << result.first << ' ' << result.second << '\n';
    }
}