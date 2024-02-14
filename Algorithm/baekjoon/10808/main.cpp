#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a{};
    int alpha[26]{};
    int s{};
    
    fill(alpha,alpha+26,0);
    
    cin >> a;
    s = a.size();
    
    for(int i=0;i<s;++i)
    {
        alpha[a[i]-'a'] += 1;
    }
    
    for(int i=0;i<26;++i)
    {
        cout << alpha[i] << " ";
    }
}