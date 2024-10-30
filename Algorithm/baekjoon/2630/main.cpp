#include <bits/stdc++.h>

using namespace std;

int m[128][128];
int whiteCount;
int blueCount;

void _recurCheckColor(int sx, int sy, int length)
{
    int value = m[sy][sx];
    if(length == 1)
    {
        if(value == 1)
            ++blueCount;
        else
            ++whiteCount;
        return;
    }
    
   
    bool isSame=true;
    
    for(int i=0;i<length && isSame;++i)
    {
        for(int j=0;j<length;++j)
        {
            if(value != m[sy+i][sx+j])
            {
                isSame = false;
                break;
            }
        }
    }
    
    if(isSame)
    {
        if(value == 1)
            ++blueCount;
        else
            ++whiteCount;
    }else
    {
        int halfLength = length/2;
        _recurCheckColor(sx,sy,halfLength);
        _recurCheckColor(sx+halfLength,sy,halfLength);
        _recurCheckColor(sx,sy+halfLength,halfLength);
        _recurCheckColor(sx+halfLength,sy+halfLength,halfLength);
    }
}

void checkColor(int length)
{
    _recurCheckColor(0,0,length);
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    
    for(int i=0;i<num;++i)
    {
        for(int j=0;j<num;++j)
        {
            cin >> m[i][j];
        }
    }
    
    checkColor(num);

    cout << whiteCount << '\n' << blueCount;
}