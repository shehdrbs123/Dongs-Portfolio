#include <iostream>
#include <string>

using namespace std;

int N,M;

void recursive(int K, string str)
{
    if(K==0)
    {
        cout << str << '\n';
        return;
    }
    for(int i=1;i<=N;++i)
    {
        string b(str);
        b.append(" ").append(to_string(i));
        recursive(K-1,b);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=1;i<=N;++i)
    {
        string d = to_string(i);
        recursive (M-1,d);
    }
    
}