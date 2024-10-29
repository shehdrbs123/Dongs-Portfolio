#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    vector<int> lope(N);
    
    for(int i=0;i<N;++i)
    {
        cin >> lope[i];
    }
    
    sort(lope.begin(),lope.end(),greater<int>());
    
    int maxWeight=1000000001;
    
    for(int i=0;i<N;++i)
    {
        int currentWeight = maxWeight + lope[i];
        float kWeight = currentWeight / (float)(i+1);
        cout << kWeight << ' ';
        int over = (kWeight-lope[i])*(i+1);
        if(over > 0)
            currentWeight -= over;
        maxWeight = min(maxWeight,currentWeight);
    }
    cout << '\n' << maxWeight;
}
