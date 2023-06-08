#include <string>
#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int input{};
    string test{};
    const char* test2;

    cin.ignore();
    getline(cin, test);
    test2 = test.c_str();
    input = atoi(test2);

    cout << pow(2,input) << endl;
};