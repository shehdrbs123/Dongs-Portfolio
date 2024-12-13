#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    queue<int> q{};
    
    for(int i=0;i<num;++i)
    {
        q.emplace(i+1);
    }
    
    while(q.size() > 1)
    {
        q.pop();
        int back = q.front();
        q.pop();
        q.emplace(back);
    }
    
    cout << q.front();
    
}