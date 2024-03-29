#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

void recursive(int sX,int eX, int sY, int eY)
{
    int gap = (eX - sX)/2;
    if(gap == 1)
    {
        int count=0;
        for(int i=sY;i<eY;++i)
        {
            for(int j=sX;j<eX;++j)
            {
                if(i==r && j==c)
                {
                    cout << result + count;
                    return;
                }
                    
                count++;
            }
        }
        return;
    }
    int midX = eX - gap;
    int midY = eY - gap;
    int add = gap*gap;
    
    if(c>= midX && r>=midY)
    {
        //4사분면
        result += 3*add;
        recursive(midX, eX,midY, eY);

    }else if (c >= midX && r< midY)
    {
        //2사분면
        result += 1*add;
        recursive(midX, eX, sY,midY);
    }else if (c < midX && r >= midY)
    {
        //3사분면
        result += 2*add;
        recursive(sX,midX,midY,eY);

    }else if (c < midX && r < midY)
    {
        recursive(sX,midX,sY,midY);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;

    int range = pow(2,N);

    recursive(0,range,0,range);
}