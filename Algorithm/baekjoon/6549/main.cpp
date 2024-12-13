#include <iostream>
#include <vector>

using namespace std;
#define ULL unsigned long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true)
    {
        int num;
        ULL result=0;
        
        cin >> num;
        if(num == 0) break;
        
        vector<pair<int,int>> v{};

        v.reserve(100000);
        
        for(int i=0;i<num; ++i)
        {
            int height;
            cin >> height;
            int width=1;
            while(!v.empty())
            {
                if(v[v.size()-1].first < height)
                    break;
                width += v[v.size()-1].second;
                v.pop_back();
            }
            
            v.emplace_back(height,width);
            
            ULL curWidth = 0;
            for(int i=v.size()-1;i>=0;--i)
            {
                curWidth += v[i].second;
                ULL square = curWidth * v[i].first;
                if(result < square) 
                {
                    result = square;
                }
            }
        }
        cout << result << '\n';
    }
}