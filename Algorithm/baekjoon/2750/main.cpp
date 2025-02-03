#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];


// 단순 sort 활용

void use_sort()
{
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n=0;
    cin >> n;
    
    for(int i=0;i<n;++i)
    {
        cin >> arr[i];
    }
    
    sort(arr,arr+n);
    
    for(int i=0;i<n;++i)
    {
        cout << arr[i] << '\n';
    }
}