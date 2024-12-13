#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    long long result = 0;
    cin >> num;
    vector<int> input(num);
    stack<pair<int,int>> s;
    for(int i=0;i<num;++i)
    {
        cin >> input[i];
    }
    
    for(int i=input.size()-1;i>=0;--i)
    {
        int count=input.size()-1-i;
        while(!s.empty())
        {
            if(s.top().first >= input[i]) break;
            s.pop();
        }
        
        if(!s.empty())
            count = s.top().second-1-i;
        result += count;
        s.emplace(input[i],i);
    }
    cout << result;
}