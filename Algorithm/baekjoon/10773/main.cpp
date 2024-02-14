#include <bits/stdc++.h>

using namespace std;

int s[100001];
int pos;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        int input;
        cin >> input;
        if(input == 0)
        {
            --pos;
        }else
        {
            s[pos] = input;
            ++pos;
        }
    }
    int result = 0;
    for(int i=0;i<pos;++i)
    {
        result += s[i];
    }
    cout << result << '\n';
}