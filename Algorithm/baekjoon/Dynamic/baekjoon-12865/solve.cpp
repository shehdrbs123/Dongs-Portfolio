#include <iostream>
#include <vector>

using namespace std;

void printGoods(vector<pair<int,int>>& goods)
{
    int size = goods.size();
    for(int i=0;i<size;i++)
    {
        cout << goods[i].first << " " << goods[i].second << endl;
    }
}
int main()
{
    int nGoodsCount{},nWeight{};
    vector<pair<int,int>> goods{};
    
    cin >> nGoodsCount >> nWeight;

    for(int i=0;i<nGoodsCount; i++)
    {
        pair<int,int> good{};
        cin >> good.first >> good.second;
        goods.emplace_back(good);
    }

    printGoods(goods);
}

