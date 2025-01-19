#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string word;
    int answer = 0;

    getline(cin,str);
    getline(cin,word);

    if(word.length() > str.length())
    {
        cout << '0';
        return 0;
    }
    

    for(int i=0;i<str.length();++i)
    {
        int result = 0;
        for(int j=i;j<str.length()-word.length()+1;++j)
        {
            bool correct = true;
            for(int k=0;k<word.length();++k)
            {
                if(str[j+k] != word[k])
                {
                    correct = false;
                    break;
                }
            }

            if(correct)
            {
                ++result;
                j += word.length()-1;
            }
        }

        if( answer < result )
        {
            answer = result;
        }
    }

    cout << answer;
}