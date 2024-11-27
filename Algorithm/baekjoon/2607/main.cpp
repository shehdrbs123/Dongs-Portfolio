#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int startStr[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result;
    int num;
    cin >> num;
    
    string first; 
    cin >> first;
    --num;

    for(int i=0;i<first.size();++i)
    {
        ++startStr[first[i]-'A'];
    }
    
    for(int i=0;i<num;++i)
    {
        string other;
        cin >> other;
        
        if(other.size() > first.size()+1) continue;

        int otherStr[26] = {0,};
        for(int j=0;j<other.size();++j)
        {
            ++otherStr[other[j]-'A'];
        }
        
        bool differ = false;
        bool differ2 = false;
        bool isSimilar = true;

        for(int j=0;j<26;++j)
        {
            int gap = abs(startStr[j]-otherStr[j]);
            if(gap == 0) continue;
            if(differ)
            {
                if(gap > 1)
                {
                    isSimilar = false;
                    break;
                }

                if(differ2)
                {
                    isSimilar = false;
                    break;
                }

                differ2 = true;
            }
            else
            {
                if(gap > 1) 
                {
                    isSimilar = false;
                    break;
                }
                
                differ = true;
            }
        }

        if(isSimilar)
            ++result;
                    
    }
    cout << result;
}