//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int size{};
    vector<int> numbers(size);
    vector<int> d(size);
    cin >> size;
    // 입력처리
    for(int i=0;i<size;++i)
    {
        int num;
        cin >> num;
        numbers.emplace_back(num);
    }

    int maxCount = -1;
    for(int i=0;i<numbers.size();++i)
    {
        int count=0;
        for(int j=i-1;j>=0;--j)
        {
            if(numbers[i] > numbers[j] && count<d[j])
                count = d[j];
        }
        d.emplace_back(count+1);
        maxCount = max(count+1,maxCount);
    }
    
    cout << maxCount;
}
