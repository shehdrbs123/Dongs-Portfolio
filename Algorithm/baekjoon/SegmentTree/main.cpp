
#include <iostream>
#include "SegmentTree.h"

using namespace std;
int N,M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    SegmentTree tree;

    vector<int> data{};

    cin >> N;

    data.resize(N);

    for(int i=0;i<N;++i)
    {
        cin >> data[i];
    }

    tree.init(data);

    cin >> M;
    
    for(int i=0;i<M;++i)
    {
        int s,e;
        cin >> s >> e;
        cout << tree.getRangeSum(s,e) << '\n';
    }
}
// 주석 없애고 데이터 넣어보삼
// 12
// 5 8 7 3 2 5 1 8 9 8 7 3
// 4
// 4 8
// 1 1
// 0 0
// 0 11
