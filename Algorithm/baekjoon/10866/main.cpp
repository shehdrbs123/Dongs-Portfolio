#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> d{};
    int N;
    cin >> N;
    cin.ignore(1);
    
    for(int i=0;i<N;++i)
    {
        string input;
        getline(cin,input);
        stringstream ss(input);
        
        ss >> input;
        if(input == "push_back")
        {
            int num;
            ss >> num;
            d.push_back(num);
        }
        else if(input == "push_front")
        {
            int num;
            ss >> num;
            d.push_front(num);
        }else if(input == "pop_back")
        {
            int num = -1;
            if(!d.empty())
            {
                num = d.back();
                d.pop_back();
            }
            cout << num << '\n';
        }else if(input == "pop_front")
        {
            int num = -1;
            if(!d.empty())
            {
                num = d.front();
                d.pop_front();
            }
            cout << num << '\n';
        }
        else if(input == "size")
        {
            cout << d.size() << '\n';
        }
        else if(input == "empty")
        {
            cout << d.empty() << '\n';
        }
        else if(input == "front")
        {
            int num = -1;
            if(!d.empty())
                num = d.front();
            cout << num << '\n';
        }
        else if(input == "back")
        {
            int num = -1;
            if(!d.empty())
                num = d.back();
            cout << num << '\n';
        }
        
    }
    
}