//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    vector<float> v{};
    int inputCount{};
    float totalScore{};
    float maxValue=-1.f;


    cin >> inputCount;
    v.reserve(inputCount);

    for(int i=0;i<inputCount;++i)
    {
        float number;
        cin >> number;
        v.push_back(number);
        maxValue = max(number,maxValue);
    }
    
    for(int i=0;i<inputCount;++i)
    {
        float score = v[i];
        
        score = v[i]/maxValue * 100.f;
        totalScore += score;
    }
    cout << fixed << totalScore/(float)inputCount;
}