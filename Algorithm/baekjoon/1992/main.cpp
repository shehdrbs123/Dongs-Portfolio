#include <bits/stdc++.h>

using namespace std;

string m[65];

void _recurCompress(int sx,int sy,int checklength)
{
    if(checklength == 1)
    {
        cout << m[sy][sx];
        return;
    }
    bool isCompress = true;

    char value = m[sy][sx];

    for(int i=0;i<checklength && isCompress;++i)
    {
        for(int j=0;j<checklength;++j)
        {
            
            if(value != m[sy+i][sx+j])
            {
                isCompress = false;
                break;
            }
        }
    }
    
    if(isCompress)
    {
       cout << value;
    }else
    {
        cout << '(';
        int nextLength = checklength/2;
        _recurCompress(sx,sy,nextLength);
        _recurCompress(sx+nextLength,sy,nextLength);
        _recurCompress(sx,sy+nextLength,nextLength);
        _recurCompress(sx+nextLength,sy+nextLength,nextLength);
        cout << ')';
    }
    
    
}

void compress(int length)
{
    _recurCompress(0,0,length);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    
    cin >> num;
    
    for(int i=0;i<num;++i)
    {
        cin >> m[i];
    }
    
    compress(num);
}
