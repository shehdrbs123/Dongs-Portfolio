#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<char>> fingers = {
    {'1','Q','A','Z'},
    {'2','W','S','X'},
    {'3','E','D','C'},
    {'4','R','F','V','5','T','G','B'},
    {'6','Y','H','N','7','U','J','M'},
    {'8','I','K',','},
    {'9','O','L','.'},
    {'0','P',';','/','-','[','\'','=',']'}
};
int fingerCount[8];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string strInput;
    
    unordered_map<char,int> map;
    
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<fingers[i].size();++j)
        {
            map.emplace(fingers[i][j],i);
        }
    }
    
    getline(cin,strInput);
    int size = strInput.length();
    
    for(int i=0;i<size;++i)
    {
        int fingerPos = map[strInput[i]];
        fingerCount[fingerPos]+=1;
    }
    
    for(int i=0;i<8;++i)
    {
        cout << fingerCount[i] << '\n';
    }
    
}