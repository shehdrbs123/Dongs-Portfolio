#include <iostream>

using namespace std;


int N, S;
bool selected[21];
int number[21];
int sum=0;
int result=0;


void print()
{
    for(int i=0;i<N;++i)
    {
        if(selected[i])
            cout << number[i] << " ";
    }
    cout << '\n';
}

void find(int idx)
{
    if(idx == N)
        return;
    
    for(int i=idx;i<N;++i)
    {
        if(selected[i])
            continue;
        selected[i] = true;
        sum += number[i];

        if(sum == S)
            ++result;
        
        find(i+1);
        
        selected[i] = false;
        sum -= number[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i=0;i<N;++i)
    {
        cin >> number[i];
    }
    
    find(0);
    cout << result;

}