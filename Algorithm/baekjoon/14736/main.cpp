#include <iostream>
#include <cmath>

using namespace std;
int N,K,A;
int getShortestNum(int t, int s)
{
    float mlPer = t*A;
    int count = (int)ceil(K/mlPer);
    int almost = (t+s)*(count-1);
    
    int rest = K-(mlPer*(count-1));
    int restTime = (int)ceil(rest/(float)A);
    
    return almost+restTime;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    int t,s;
    
    cin >> N >> K >> A;

    int shortest = 1000000000;

    for(int i=0;i<N;++i)
    {
        int t,s;
        cin >> t >> s;

        int getTime = getShortestNum(t,s);
        //cout << getTime << '\n';
        if(shortest > getTime)
            shortest = getTime;
    }

    cout << shortest;
}
