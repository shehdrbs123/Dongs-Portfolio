#include <bits/stdc++.h>

using namespace std;

string normal[] = {"", "Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
string special[] = {"","Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh"};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int c;
    
    cin >> c;
    
    for(int i=0;i<c;++i)
    {
        int a,b;
        cin >> a >> b;
        cout << "Case " << i+1 << ": ";
        if((a==5 && b==6 )|| ( a==6 && b==5))
            cout << "Sheesh Beesh" << '\n';
        else if(a==b)
            cout << special[a] <<'\n';
        else if (a>b)
            cout << normal[a] << " " << normal[b] << '\n';
        else 
            cout << normal[b] << " " << normal[a] << '\n';

    }
}