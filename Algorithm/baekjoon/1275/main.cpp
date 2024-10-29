#include <iostream>

using namespace std;

int N,Q;
long long dat[100003];
long long tree[100003*4];

long long init(int start, int end, int node)
{
    if(start == end) return tree[node] = dat[start]; 
    int mid = (start + end) / 2;
    return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

long long find(int start, int end, int node, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end) /2;
    return find(start,mid,node*2,left,right) + find(mid+1,end,node*2+1,left,right);
}

void update(int start, int end, int node, int index, long long dif)
{
    if(start>index || index > end) return;
    tree[node] += dif;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start,mid,node*2,index,dif);
    update(mid+1,end,node*2+1,index,dif);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    
    for(int i=1;i<=N;++i)
    {
        cin >> dat[i];
    }

    init(1,N,1);
    
    for(int i=0;i<Q;++i)
    {
        int x,y,a;
        long long b;
        cin >> x >> y >> a >> b;
        if(x>y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        cout << find(1,N,1,x,y) << '\n';
        long long dif = -(dat[a]-b);
        update(1,N,1,a,dif);
        dat[a] = b;
    }
        
}