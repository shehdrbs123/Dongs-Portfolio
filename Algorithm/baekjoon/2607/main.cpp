#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int startStr[26];

void print(int * ptr, int size)
{
    for(int i=0;i<size;++i)
    {
        cout << *(ptr+i) << ' ';
    }
    cout << '\n';
}

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
    cout << "======================================\n";
    for(int i=0;i<first.size();++i)
    {
        ++startStr[first[i]-'A'];
    }

    for(int i=0;i<num;++i)
    {
        string other;
        cin >> other;
        
        if(abs((int)first.size() - (int)other.size()) > 1) continue;

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
        {
            cout << other <<'\n';
            ++result;
        }
            
                    
    }
    cout << result;
}