#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    long long result = 0;
    cin >> num;
    
    stack<pair<int,long long>> s{};

    
    for(int i=0;i<num;++i)
    {
        int height, count=0;
        int sameCount=1;
        cin >> height;
        
        while(!s.empty())
        {
            if(s.top().first > height)
            {
                break;
            }

            if(s.top().first == height)
                sameCount += s.top().second;
            count += s.top().second;
            s.pop();
        }

        if(!s.empty())
            count++;

        result += count;
        //cout << count << " " ;
        s.emplace(height,sameCount);
    }
    //cout << '\n';
    cout << result;

}