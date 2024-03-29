#include <iostream>
using namespace std;

void preOrder(pair<int,int>  v[],int currentIdx)
{ 
    cout << char(currentIdx+'A');
    if(v[currentIdx].first != '.')
        preOrder(v,v[currentIdx].first-'A');
    if(v[currentIdx].second != '.')
        preOrder(v,v[currentIdx].second-'A');
}

void inOrder(pair<int,int> v[],int currentIdx)
{
    if(v[currentIdx].first != '.')
        inOrder(v,v[currentIdx].first-'A');
    cout << (char)(currentIdx+'A');
    if(v[currentIdx].second != '.')
        inOrder(v,v[currentIdx].second-'A');
}

void postOrder(pair<int,int> v[],int currentIdx)
{
    if(v[currentIdx].first != '.')
        postOrder(v,v[currentIdx].first-'A');
    if(v[currentIdx].second != '.')
        postOrder(v,v[currentIdx].second-'A');
    cout << (char)(currentIdx+'A');
}

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    pair<int,int> v[26];
    cin >> N;
    
    for(int i=0;i<N;++i)
    {
        char root, left, right;
        cin >> root >> left >> right;
        
        int rootIdx = root-'A';
        v[rootIdx].first = left;
        v[rootIdx].second = right;
    }
    
    preOrder(v,0);
    cout << '\n';
    inOrder(v,0);
    cout << '\n';
    postOrder(v,0);
    cout << '\n';
    
}