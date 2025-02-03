#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double result = 0;
vector<pair<int,int>> v{};
bool isSave = false;
void solveHanoi(int num, int start, int end, int sub)
{
    if(num == 1)
    {
        if(isSave)
        {
            v.emplace_back(start,end);
        }
        return;
    }
    solveHanoi(num-1,start,sub,end);
    if(isSave)
    {
        v.emplace_back(start,end);
    }
    solveHanoi(num-1,sub,end,start);
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    isSave = num <=20;
    
    result = pow(2,num)-1;
    cout << result << '\n';
    if(num <= 20)
    {
        solveHanoi(num,1,3,2);
        for(int i=0;i<v.size();++i)
        {
            auto value = v[i];
            cout << value.first << " " << value.second <<'\n';
        }
    }

}