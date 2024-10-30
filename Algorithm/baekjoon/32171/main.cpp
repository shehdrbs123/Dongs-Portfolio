#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int result;
    int a, b, c, d;
    int ra, rb, rc, rd;
    
    cin >> n;
    cin >> ra >> rb >> rc >> rd;
    
    result = 2 * (abs(rc - ra) + abs(rd - rb));
    cout << result << '\n';
    
    for(int i=1;i<n;++i)
    {
        cin >> a >> b >> c >> d;
        
        if(ra > a) ra = a;
        if(rb > b) rb = b;
        if(rc < c) rc = c;
        if(rd < d) rd = d;
        
        result = 2 * (abs(rc - ra) + abs(rd - rb));
        cout << result << '\n';
    }
}