#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;
void PrintDFS(vector<set<int>>& vectorVertex,int size, int startPoint);
void PrintBFS(vector<set<int>>& vectorVertex,int size, int startPoint);
int main()
{
    int vertex{}, edge{}, startNum{};
    
    cin >> vertex >> edge >> startNum;
    vector<set<int>> vectorVertex{};

    for(int i=0;i<=vertex;++i)
    {
        vectorVertex.emplace_back(set<int>());
    }


    for(int i=0;i<edge;++i)
    {
        int edge1{};
        int edge2{};
        
        cin >> edge1 >> edge2;

        vectorVertex[edge1].emplace(edge2);
        vectorVertex[edge2].emplace(edge1);
    }

    PrintDFS(vectorVertex,vertex,startNum);
    PrintBFS(vectorVertex,vertex,startNum);
    
}

void PrintDFS(vector<set<int>>& vectorVertex,int size, int startPoint)
{
    vector<bool> visit;
    stack<pair<int,set<int>>> q;

    for(int i=0;i<=size;++i)
    {
        visit.emplace_back(false);
    }
    visit[0] = true;
    
    q.emplace(startPoint,vectorVertex[startPoint]);
    visit[startPoint] = true;
    cout << startPoint << " ";  
    while(!q.empty())
    {
        pair<int,set<int>> edgeVertex = q.top();q.pop();
  
        for(int vertex : edgeVertex.second)
        {
            if(!visit[vertex])
            {
                cout << vertex << " ";

                q.emplace(edgeVertex.first,edgeVertex.second);
                q.emplace(vertex,vectorVertex[vertex]);
                visit[vertex] = true;

                break;
            }
        }
    }
    cout << '\n';
}


void PrintBFS(vector<set<int>>& vectorVertex,int size, int startPoint)
{
    vector<bool> visit;
    queue<pair<int,set<int>>> q;
    for(int i=0;i<=size;++i)
    {
        visit.emplace_back(false);
    }
    visit[0] = true;
    
    q.emplace(startPoint,vectorVertex[startPoint]);
    visit[startPoint] = true;
    
    while(!q.empty())
    {
        pair<int,set<int>> edgeVertex = q.front();q.pop();
        cout << edgeVertex.first << " ";
        for(int vertex : edgeVertex.second)
        {
            if(!visit[vertex])
            {
                q.emplace(vertex,vectorVertex[vertex]);
                visit[vertex] = true;
            }
        }
    }
    cout << '\n';
}