#include <iostream>
#include <string>
using namespace std;

string inputStr;
string inputWord;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin,inputStr);
    getline(cin,inputWord);
    
    int strSize = inputStr.length();
    int wordSize = inputWord.length();
    int result = 0;
    
    int count=0;
    for(int i=0;i<strSize;++i)
    {
        bool isOK = false;
        for(int j=0;i<strSize && j<wordSize;++j)
        {
            if(inputStr[i+j] != inputWord[j])
            {
                break;
            }

            if(j==(wordSize-1))
            {
                isOK=true;
                i+=wordSize-1;
            }   
        }
        if(isOK)
        {
            ++count;
        }    
    }
    
    
    cout << count;
}