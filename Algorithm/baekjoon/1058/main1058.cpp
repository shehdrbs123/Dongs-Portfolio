#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
string str[50];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int result = -1;
    for(int i=0;i<N;++i)
    {
        cin >> str[i];
    }
    
    
    for(int i=0;i<N;++i)
    {
        int twoFriendCount=0;
        for(int j=0;j<N;j++)
        {
            if(i==j) continue;
            
            if(str[i][j] == 'Y') 
            {
                ++twoFriendCount;
            }
            else
            {
                for(int k=0;k<N;++k)
                {
                    if(str[i][k] == 'N') continue;
                    if(str[i][k] == str[j][k])
                    {
                        ++twoFriendCount;
                        break;
                    }
                }
            }
        }
        result = max(result,twoFriendCount);
    }
    
    cout << result;
}