#include "SegmentTree.h"
#include <iostream>

SegmentTree::SegmentTree()
{
    
}

void SegmentTree::init(const vector<int> &data)
{
    this->data = data;
    segmentTree.resize(data.size()*4);
    init(0,data.size()-1,1);   
    std::cout << endl;
}

int SegmentTree::getRangeSum(int start, int end)
{
    return sum(0,data.size()-1,1,start,end);
}

int SegmentTree::init(int start, int end, int node)
{
    if(start == end) return segmentTree[node] = data[start];
    int mid = (start+end) / 2;
    return segmentTree[node] = init(start,mid,node*2) + init(mid+1, end, node*2+1);
}

int SegmentTree::sum(int start, int end, int node, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start  && end <= right) return segmentTree[node];

    int mid = (start + end) / 2;
    return sum(start,mid,node*2,left,right) + sum(mid+1, end, node*2+1, left,right);
}

void SegmentTree::update(int start, int end, int node, int index, int dif)
{
    if(index < start || index > end) return;
    segmentTree[node] += dif;
    if(start == end) return;
    int mid = (start+end) /2;
    update(start,mid,node*2,index,dif);
    update(mid+1,end,node*2+1,index, dif);
}
