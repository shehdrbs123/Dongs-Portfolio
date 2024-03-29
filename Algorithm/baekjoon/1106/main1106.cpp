#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int C,N;

int dp[1001][20];


int compare(const pair<int,int>& a, const pair<int,int>& b)
{
        float aRate = (float)a.second / (float)a.first;
        float bRate = (float)b.second / (float)b.first;
        return  aRate - bRate;
}    

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> N;
    
    
    vector<pair<int,int>> v{};
    vector<int> vCount(N);
    int result = 0;

    v.reserve(N);

    for(int i=0;i<N;++i)
    {
        int cost,effect;
        cin >> cost >> effect;
        v.emplace_back(cost,effect);
    }

    sort(v.begin(),v.end(),compare);
    vCount[0] = ceil((double)C/(double)(v[0].second));
    int currentPerson = v[0].second * vCount[0];
    int currentEffect = v[0].first * vCount[0];    
    
    for(int i=1;i<N;++i)
    {
        int count = vCount[i-1];
        int tempResultEffect = currentEffect;
        int tempResultPerson = currentPerson;
        for(int k=1;k<=count;++k)
        {
            int tempCurrentPerson = tempResultEffect-v[i-1].second*k;
            int tempCurrentEffect = tempResultPerson-v[i-1].first*k;
            int restPerson = C-tempCurrentPerson;
            int restRate = ceil((double)restPerson/(double)v[i].first);
            int resultEffect = tempCurrentEffect+restRate*v[i].first;
            int resultPerson = tempCurrentPerson+restRate*v[i].second;

            if(tempResultEffect > resultEffect)
            {
                tempResultEffect = resultEffect;
                tempResultPerson = resultPerson;
            }
            else
            {
                break;
            }

        }
        currentEffect = tempResultEffect;
        currentPerson = tempResultPerson;
    }

    cout << currentEffect;
}