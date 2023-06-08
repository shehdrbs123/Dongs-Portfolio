#include <iostream>

using namespace std;
int main()
{
    int input{};
    int count{};
    cin >> input;
 
    count = 0;
    for(int i=1;i<input;i++)
    {
        count += i;
    }
    
    cout << count << endl;
    cout << 2 << endl;
}