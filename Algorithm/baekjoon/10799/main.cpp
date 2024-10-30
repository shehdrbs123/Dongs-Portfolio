#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int s;
    int stackCount=0;
    int result=0;
    cin >> str;
    s = str.size();

    
    for(int i=0;i<s;++i)
    {
        if(str[i] == '(')
        {
            ++stackCount;
        }
        else
        {
            if(i-1 >= 0)
            {
                if(str[i-1] == '(')
                {
                    --stackCount;
                    result+=stackCount;
                }else
                {
                    --stackCount;
                    ++result;
                }
            }
        }
    }
    cout << result;
}