#include <iostream>
#include <string>
#include <functional>

using namespace std;
int MAX_LENGTH = 51;
size_t hashValue[7];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    hash<string> hashFunction;
    
    int n;
    string strInput;
    
    hashValue[0] = hashFunction("Never gonna give you up");
    hashValue[1] = hashFunction("Never gonna let you down");
    hashValue[2] = hashFunction("Never gonna run around and desert you");
    hashValue[3] = hashFunction("Never gonna make you cry");
    hashValue[4] = hashFunction("Never gonna say goodbye");
    hashValue[5] = hashFunction("Never gonna tell a lie and hurt you");
    hashValue[6] = hashFunction("Never gonna stop");

    cin >> n;

    
    cin.ignore();
    
    for(int i=0;i<n;++i)
    {
        getline(cin, strInput);
        size_t num = hashFunction(strInput);
        bool isInvolved=false;
        for(int j=0;j<7;++j)
        {
            if(hashValue[j] == num)
            {
                isInvolved = true;
                break;
            }
        }
        if(!isInvolved)
        {
            cout << "Yes";
            return 0;
        }
    }
    
    cout << "No";
    return 0;
}