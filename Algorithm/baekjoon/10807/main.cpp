#include <iostream>
#include <vector>

using namespace std;
int N,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 0;
    cin >> N;
    
    vector<int> v(N);
    
    for(int i=0;i<N;++i)
    {
        cin >> v[i];
    }
    
    cin >> t;
    
    for(int i=0;i<N;++i)
    {
        if(t == v[i])
            result += 1;
    }
    
    cout << result;
}