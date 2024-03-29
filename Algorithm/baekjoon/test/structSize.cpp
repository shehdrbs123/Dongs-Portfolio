#include <bits/stdc++.h>

using namespace std;

struct test{
    char a2;
    int a3;
    double a1;
   
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "int size : " << sizeof(int) << '\n';
    cout << "int size : " << sizeof(double) << '\n';
    cout << "int size : " << sizeof(char) << '\n';
    cout << "int size : " << sizeof(test) << '\n';

    cout.precision(10);

    float tmp = 0.0f;
    
    cout << 0 << endl;
    cout << 0.0 << endl;
    cout << 0.0f << endl;
    cout << 0.0f/0.0f << endl;
    cout << 0.0/0.0f <<  endl;
    cout << 0.0f/0.0 << endl;

}