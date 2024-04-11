#include <vector>
using namespace std;

class SegmentTree
{
public :
    vector<int> data;
    vector<int> segmentTree;
public : 
    SegmentTree();
    SegmentTree (const SegmentTree&) = delete;
    SegmentTree& operator=(const SegmentTree&) = delete;
    void init(const vector<int>& data);
    int getRangeSum(int start, int end);


private :
    int init(int start, int end, int node);
    int sum(int start, int end, int node, int left, int right);
    void update (int start, int end, int node, int index, int dif);

};