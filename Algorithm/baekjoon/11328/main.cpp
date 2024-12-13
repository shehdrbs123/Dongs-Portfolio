#include <iostream>
#include <string>

using namespace std;

int alpha[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    for(int i=0;i<num;++i)
    {
        bool isPossible = true;
        string strA, strB;
        memset(alpha,0,104);
        
        cin >> strA >> strB;
        
        if(strA.size() != strB.size())
        {
            cout << "Impossible" << '\n';
            continue;
        }
            
        for(int i=0;i<strA.size();++i)
        {
            int idx = strA[i] - 'a';
            ++alpha[idx];
        }
        
        for(int i=0;i<strB.size();++i)
        {
            int idx = strB[i] - 'a';
            if(alpha[idx] <= 0)
            {
                isPossible = false;
                break;
            }
            --alpha[idx];
        }
        
        if(isPossible)
        {
            cout << "Possible" << '\n';
        }else
        {
            cout << "Impossible" << '\n';
        }
        
    }
}