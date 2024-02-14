#include <bits/stdc++.h>

using namespace std;



int func2(int arr[], int N)
{
    int* a;
    int* b;

    a = &arr[0];
    b = &arr[N-1];
    sort(arr,arr+N);

    for(;a<b;)
    {
        int tmp = *a+*b;
        if(tmp > 100)
        {
            --b;
        }else if (tmp<100 ){
            ++a;
        }else
        {
            return 1;
        }
    }
    return 0;
}

//배열을 비트셋으로 활용하기! 
int func(int arr[], int n)
{
    bool tmp[101]{};

    for(int i=0;i<n;++i)
    {
        int targetNum = 100-arr[i];
        if(tmp[targetNum] == true)
        {
            return 1;
        }
        tmp[arr[i]] = true;
    }
    return 0;
}

int main()
{
    int a[] = {1,52,48};
    int b[] = {50,42};
    int c[] = {4,13,63,87};
    int d[] = {1,23,53,77,60};


    cout << func(a,3) << "\n";
    cout << func(b,2) << "\n";
    cout << func(c,4) << "\n";
    cout << func(d,5) << "\n";

}

