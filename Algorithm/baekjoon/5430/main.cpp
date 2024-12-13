#include <iostream>
#include <deque>

using namespace std;
char command[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int inputCount;
    cin >> inputCount;

    for(int i=0;i<inputCount;++i)
    {
        deque<int> dq{};
        int arraySize;
        bool isError = false;
        int commandLength = 0;
        cin.ignore();
        for(;commandLength < 100001;++commandLength)
        {
            char c = cin.get();
            if(c == '\n')
                break;
            command[commandLength] = c;
        }

        cin >> arraySize;

        int number=0;
        while(true)
        {
            char input;
            cin >> input;
            if(input == '[')
                continue;
            if(input == ',')
            {
                dq.emplace_back(number);
                number = 0;
                
                continue;
            }
            if(input == ']')
            {
                if(number != 0)
                    dq.emplace_back(number);
                break;
            }

            number *= 10;
            number += input-'0';
        }
        
        bool frontOut = true;
        for(int i=0;i<commandLength;++i)
        {
            if(command[i] == 'R')
            {
                frontOut = !frontOut;
            }
            else
            {
                if(dq.empty())
                {
                    isError = true;
                    break;
                }
                    
                if(frontOut)
                {
                    dq.pop_front(); 
                }
                else
                {
                    dq.pop_back();
                }
            }
        }
        
        
        if(isError)
        {
            cout << "error\n";
        }
        else 
        {
            cout << '[';
            if(!dq.empty())
            {
                if(frontOut)
                {
                    while(dq.size() != 1)
                    {
                        cout << dq.front() << ',';
                        dq.pop_front();
                    }
                    cout << dq.front();
                }
                else
                {
                    while(dq.size() != 1)
                    {
                        cout << dq.back() << ',';
                        dq.pop_back();
                    }
                    cout << dq.back();
                }
            }
            cout << "]\n";
        }
    }
    
}