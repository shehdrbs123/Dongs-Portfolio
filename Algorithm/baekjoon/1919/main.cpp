#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string w1,w2;
    int result=0;
    vector<int> w1v(26);
    vector<int> w2v(26);

    cin >> w1;
    cin >> w2;
    
    int size = w1.length();
    for(int i=0;i<size;++i)
    {
        int idx = w1[i]-'a';
        w1v[idx] += 1;
    }
    
    size = w2.length();
    for(int i=0;i<size;++i)
    {
        int idx = w2[i]-'a';
        w2v[idx] += 1;
    }
    
    for(int i=0;i<26;++i)
    {
        int gap = abs(w1v[i] - w2v[i]);
        result += gap;
    }
    
    cout << result;
}