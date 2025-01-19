#include <iostream>
#include <vector>

using namespace std;

int x,y,dx,dy;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for(int i=0;i<num; ++i)
    {
        int result = 0;
        cin >> x >> y >> dx >> dy;

        bool board[y][x] = {false,};
        int right=x,top=y;
        bool setNight=true;
        while(right>=0 && top >=0)
        {
            for(int i=0;i<top;++i)
            {
                for(int j=0;j<right;++j)
                {
                    board[i][j] = setNight;
                }
            }
            setNight = !setNight;
            right -= dx;
            top -=dy;

        }

        for(int i=0;i<y;++i)
        {
            for(int j=0;j<x;++j)
            {
                if(board[i][j])
                    ++result;
            }
        }

        cout << result <<'\n';
    }
}