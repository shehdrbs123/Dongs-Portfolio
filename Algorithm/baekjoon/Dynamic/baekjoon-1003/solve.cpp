#include <iostream>
#include <vector>
#include <map>
using namespace std;


void makeDynamic(vector<pair<int,int>>& dynamic, int n)
{
    int capacity = dynamic.capacity();
    if(n>capacity)
        dynamic.reserve(n);

    int lastSize= dynamic.size();

    for(int i=lastSize; i<=n;i++)
    {
        pair<int,int> a = make_pair(0,0);
        a.first = dynamic[i-2].first + dynamic[i-1].first;
        a.second = dynamic[i-2].second + dynamic[i-1].second;

        dynamic.emplace_back(a);
    }
    
}
int main()
{
    vector<pair<int,int>> dynamic{};
    int n{};
    int size{};

    dynamic.emplace_back(make_pair(1,0));
    dynamic.emplace_back(make_pair(0,1));

    cin >> n;
    
    for(int i=0;i<n;i++)
    {   
        int input{};
        int size{};
        pair<int,int> last{};
        
        cin >> input;
        size = dynamic.size();

        if(input+1>size)
            makeDynamic(dynamic,input);

        last = dynamic[input];
        cout << last.first << " " << last.second<< endl;
    }
}

