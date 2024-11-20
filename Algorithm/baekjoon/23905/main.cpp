#include <bits/stdc++.h>

using namespace std;

int T, K, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    for(int i=0;i<T;++i)
    {
        cin >> N >> K;
        int result=0;
        int preNum = 0;
        int countdown = 0;
        bool findK = false;
        
        for(int j=0;j<N;++j)
        {
            int num;
            cin >> num;
            if(findK)
            {
                if(num == preNum-1)
                {
                    ++countdown;
                    if(countdown == K)
                    {
                        ++result;
                        findK = false;
                        countdown =0;
                    }
                        
                }else
                {
                    findK = false;   
                    countdown = 0;
                }
            }else
            {
                if(num != K) continue;
 
                findK = true;
                countdown = 1;
            }
            preNum = num;
        }
        
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
       
}