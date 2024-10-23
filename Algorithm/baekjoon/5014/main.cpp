#include <iostream>
#include <queue>

using namespace std;

int F,S,G;
int U,D;

int visited[1000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> F >> S >> G >> U >> D;
    
    if(G==S)
    {
        cout << 0;
        return 0;
    }

    queue<int> q;
    
    q.push(S);
    visited[S] = 1;
    
    while(!q.empty())
    {
        int c = q.front();q.pop();
        int up = c+U;
        int down = c-D;
        
        if(up <= F && visited[up] == 0)
        {
            visited[up] = visited[c]+1;
            q.push(up);
        }
        
        if(down > 0 && visited[down] == 0)
        {
            visited[down] = visited[c]+1;
            q.push(down);
        }
        
    }
    
    if(visited[G] == 0)
        cout << "use the stairs";
    else
        cout << visited[G]-1;
}