#include <iostream>
#include <queue>
using namespace std;


//우선 순위 큐 활용
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq{};
    for(int i=0;i<n;++i)
    {
        int n = 0;
        cin >> n;
        pq.emplace(n);
    }

    for(int i=0;i<n;++i)
    {
        cout << pq.top() << '\n';
        pq.pop();
    }
}