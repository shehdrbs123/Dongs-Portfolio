#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, sx, sy;
    cin >> n;
    cin >> sx >> sy;
    double dist = numeric_limits<double>::max();
    int tx=0, ty=0;
    for(int i=1;i<n;++i)
    {
        int ex, ey;
        cin >> ex >> ey;
        double otherdist = sqrt(pow(ex-sx,2.0) + pow(ey-sy,2.0));
        if(dist > otherdist)
        {
            dist = otherdist;
            tx = ex;
            ty = ey;
        }  
    }
    
    cout << sx << ' ' << sy << '\n';
    cout << tx << ' ' << ty << '\n';
    cout << fixed;
    cout.precision(2);
    cout << dist;
    
}