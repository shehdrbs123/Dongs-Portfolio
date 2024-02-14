#include <bits/stdc++.h>

using namespace std;

int s[10001]{};
int pos = 0;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    
    cin >> N;
    cin.ignore(1);
    
    
    for(int i=0;i<N;++i)
    {
        string input;
        getline(cin,input,'\n');
        
        stringstream ss1(input);
        ss1 >> input;
        if(input.compare("push")==0)
        {
            int num;
            ss1 >> num;
            s[pos] = num;
            ++pos;
        }else if(input.compare("pop")==0)
        {
            int num = -1;
            if(pos>0)
            {
                --pos;
                num = s[pos];
            }
            cout << num << '\n';
                
        }else if(input.compare("top")==0)
        {
            int num = -1;
            if(pos > 0)
            {
               num = s[pos-1];
            }
            cout << num << '\n';
        }else if(input.compare("size")==0)
        {
            cout << pos << '\n';
        }else if(input.compare("empty")==0)
        {
            int num = 1;
            if(pos > 0)
                num = 0;
            cout << num << '\n';
        }
    }
}