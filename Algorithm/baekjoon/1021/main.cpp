#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int count = 0;
    cin >> n >> m;
    deque<int> dq{};

    for(int i=0;i<n;++i)
    {
        dq.emplace_back(i+1);
    }

    for(int i=0;i<m;++i)
    {
        int num;
        cin >> num;
        int left = 0;
        int right = 0;
        auto itr = dq.begin();
        for(;itr != dq.end();++itr)
        {
            if(*itr == num)
                break;
            ++right;
        }
        left = dq.size() - right;

        int result;
        if(left >= right)
        {   
            while(dq.front() != num)
            {
                int f = dq.front();
                dq.pop_front();
                dq.emplace_back(f);
            }
            result = right;
        }
        else
        {
            while(dq.front() != num)
            {
                int f = dq.back();
                dq.pop_back();
                dq.emplace_front(f);
            }
            result = left;
        }
        dq.pop_front();

        count += result;
    }

    cout << count;
}
