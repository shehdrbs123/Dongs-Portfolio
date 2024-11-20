#include <bits/stdc++.h>

using namespace std;

int T, N, K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> T;
    for(int i=0;i<T;++i)
    {
        cin >> N >> K;
        int preNum = -1;
        int countDown = 0;
        int result = 0;
        bool isFindK = false;
        for(int j=0;j<N;++j)
        {
            int num;
            cin >> num;
            
            if(isFindK)
            {
                if(num == preNum-1)
                {
                    ++countDown;
                    if(countDown == K)
                    {
                        ++result;
                        countDown = 0;
                        isFindK = false;
                    }    
                }else
                {
                    isFindK = false;
                    countDown = 0;
                }
            }
            
            if(num == K) 
            {
                isFindK = true;
                countDown = 1;
            }
            preNum = num;
        }
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
    
}