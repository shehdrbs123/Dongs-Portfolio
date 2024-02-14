#include<bits/stdc++.h>

using namespace std;

int q[10001];
int head,tail;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        string input;
        cin >> input;
        if(input == "push")
        {
            int num;
            cin >> num;
            q[tail] = num;
            ++tail;
        }else if(input == "pop")
        {
            int num = -1;
            if(tail > head)
            {
                num = q[head];
                ++head;
            }
            cout << num << "\n";
        }else if(input == "size")
        {
            int num = tail - head;
            cout << num << '\n';
        }else if(input == "empty")
        {
            int num = 0;
            if(tail - head == 0)
                num = 1;
            cout << num << '\n';
        }else if(input == "front")
        {
            int num = -1;
            if(tail - head > 0)
                num = q[head];
            cout << num << '\n';
        }  
        else if(input == "back")
        {
             int num = -1;
            if(tail - head > 0)
                num = q[tail-1];
            cout << num << '\n';
        }
    }
}