#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int inputCount = 1;
    while(true)
    {
        string input;
        cin >> input;
        
        if(input[0] == '-' )
            break;
        
        int sin=0;
        int needChange=0;
        
        for(int i=0;i<input.size();++i)
        {
            if(input[i] == '{')
            {
                ++sin;
            }else
            {
                if(sin > 0)
                {
                     --sin;   
                }else
                {
                    needChange++;
                    ++sin;
                }
            }
        }
        
        if(sin > 0)
            needChange += round(sin/2);
        cout << inputCount << ". " << needChange << '\n';
        
        ++inputCount;
    }
}