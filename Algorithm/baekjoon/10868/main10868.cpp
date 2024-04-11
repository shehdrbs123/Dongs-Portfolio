#include <iostream>
#include <cmath>
using namespace std;


int N,M;
int datas[100001];
int tree[100001*4];

int makeSegmentTree(int start, int end, int node)
{
    if(start == end) return tree[node] = datas[start];
    
    int mid = (start+end)/2;
    int left = makeSegmentTree(start, mid,node*2);
    int right = makeSegmentTree(mid+1, end, node*2+1);
    int minValue = min(left,right);
    return tree[node] = minValue;
}

int getRangeMin(int start, int end, int node, int left, int right)
{
    if(left > end || right < start) 
    {
        return 1000000001;
    }
    if(left <= start && end <= right) 
    {
        return tree[node];
    }
    int mid = (start+end) / 2;
    int nextLeft = getRangeMin(start,mid,node*2,left,right);
    int nextRight = getRangeMin(mid+1,end,node*2+1,left,right);

    return min(nextLeft,nextRight);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=0;i<N;++i)
    {
        cin >> datas[i];
    }
    
    makeSegmentTree(0,N-1,1);


    for(int i=0;i<M;++i)
    {
        int s,e;
        cin >> s >> e;
        cout << getRangeMin(0,N-1,1,s-1,e-1) << '\n';
    }
}