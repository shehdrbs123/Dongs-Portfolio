#include <iostream>
#include <ctime>

void multyTest(int repeatCount)
{
    clock_t start, finish;
    int value = 1;

    start = clock();
    for(int i=0;i<repeatCount;++i)
    {
        value *=2;
    }
    finish = clock();

    std:: cout << "multy : " << finish - start << '\n';
}


void shiftTest(int repeatCount)
{
    clock_t start, finish;
    int value = 1;

    start = clock();
    for(int i=0;i<repeatCount;++i)
    {
        value <<= 1;
    }
    finish = clock();
    std:: cout << "shift : " << finish - start << '\n';
}

int main()
{
    clock_t start, finish;
    int repeatCount = 1000000000;
    // ms 단위임
    for(int i=0;i<10;++i)
    {
        shiftTest(repeatCount);
        multyTest(repeatCount);
    }
}

