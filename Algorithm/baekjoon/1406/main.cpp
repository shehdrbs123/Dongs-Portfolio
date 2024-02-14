#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input{};
    int iCount{};
    char command[4];
    list<char> d{};
    list<char>::iterator pCur{};
    
    cin >> input;
    cin >> iCount;
    cin.ignore(1);
    for(int i=0;i<input.size();++i)
    {
       d.emplace_back(input[i]);
    }
    
    pCur = d.end();
    for(int i=0;i<iCount;++i)
    {
        char c{};

        cin.getline(command,4,'\n');
        c=command[0];
        
        if(c == 'P')
        {
            d.insert(pCur,command[2]);
        }else if(c == 'D')
        {
            if(pCur != d.end())
                ++pCur;
        }else if(c == 'L')
        {
            if(pCur != d.begin())
                --pCur;
        }else if(c == 'B')
        {
            if(pCur != d.begin())
            {
                --pCur;
                pCur = d.erase(pCur);
            }
        }
    }
    
    
    for(char a : d)
    {
        cout << a;
    }
    
}