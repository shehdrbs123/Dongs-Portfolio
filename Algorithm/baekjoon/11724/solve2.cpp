#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[1001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<vector<int>> vertexes{};    
    queue<int> q{};
    int vertex{}, edges{};
    int count{};
    
    cin >> vertex >> edges;
    
    vertexes.resize(vertex+1);
    
    for(int i=0;i<edges;++i)
    {
        int vertex1{}, vertex2{};
        cin >> vertex1 >> vertex2;
        vertexes[vertex1].emplace_back(vertex2);
        vertexes[vertex2].emplace_back(vertex1);
    }

    
    for(int i=1;i<=vertex;++i)
    {
        if(visited[i])
           continue;
        
        q.emplace(i);
        visited[i] = true;
        
        while(!q.empty())
        {
            int pos = q.front(); q.pop();
            int size = vertexes[pos].size();
            for(int j=0; j<size;++j)
            {
                int next = vertexes[pos][j];
                if(visited[next]) continue;
                
                q.emplace(next);
                visited[next] = true;
            }
        }

        count++;
    }
    cout << count;
}