#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
inline int solve1(vector<int>& woods, const int amountWood);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int woodCount{}, needWoods{};
    int result{};
    
    cin >> woodCount >> needWoods;
    vector<int> woods(woodCount);
    for(int i=0;i<woodCount;++i)
    {
        int height;
        cin >> height;
        woods[i] = height;
    }
    
    result = solve1(woods, needWoods);
    cout << result;
}


inline int solve1(vector<int>& woods, const int amountWood)
{
    int cutHeight;
    int needWoods = amountWood;

    sort(woods.begin(),woods.end(),greater<int>());
    cutHeight = woods[0];
    for(int i=1;i<woods.size();++i)
    {
        needWoods -= (woods[i-1]-woods[i])*i;
        cutHeight = woods[i];
        if(needWoods == 0)
        {
            return cutHeight;            
        }else if (needWoods < 0)
        {
            return cutHeight - needWoods/i;
        }
    }
    float restHeightf = (float)needWoods / woods.size();
    int restHeight = ceil(restHeightf);
    return cutHeight - restHeight;
}