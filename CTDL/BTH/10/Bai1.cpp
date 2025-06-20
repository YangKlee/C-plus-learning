#include <bits/stdc++.h>
#define MAX_VERTICES 100
#define INF 1000
using namespace std;

struct AdjList
{
    int adjVertex;
    float weight;
    AdjList* next;
};
struct AdjListGraph
{
    int numVertices;
    AdjList* AdjList[MAX_VERTICES];
};
void readGraphFromFile(AdjListGraph& g, string fileName)
{
    ifstream file(fileName);
    file >> g.numVertices;
    for (int i = 0; i < g.numVertices; i++)
    {
        g.AdjList[i] = nullptr;
        for (int j = 0; j < g.numVertices; j++)
        {
            float weight;
            file >> weight;
            if(weight != INF)
            {
                AdjList* newNode = new AdjList;
                newNode->adjVertex = j;
                newNode->weight = weight;
                newNode->next = g.AdjList[i];
                g.AdjList[i] = newNode;
            }
        }
    }
    file.close();
}
void printGraph(AdjListGraph g)
{
    cout << "So dinh " << g.numVertices << endl;
    for (int i = 0; i < g.numVertices; i++)
    {
            cout << "adjList[" << i << "]: ";
        for(AdjList* p = g.AdjList[i]; p != nullptr; p = p->next)
        {
            cout << p->adjVertex << "(" << p->weight << ")" ;
        }
        cout << endl;

    }
    cout << endl;
}
void printPath(int parent[], int s, int v)
{
    if(v==s){
        cout << s << " ";
        return;
    }
    printPath(parent, s, parent[v]);
    cout << v << " ";
}
void PathBFS(AdjListGraph g, int s, int parent[])
{
    bool visited[MAX_VERTICES]= {false};
    for(int i = 0; i < g.numVertices; i++)
        parent[i] = -1;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (AdjList* p = g.AdjList[curr]; p!=nullptr; p=p->next)
        {
            if(!visited[p->adjVertex])
            {
                visited[p->adjVertex] = true;
                parent[p->adjVertex] = curr;
                q.push(p->adjVertex);
            }
        }
    }
    
}
void DFSUtil(AdjListGraph& graph, int u, int visited[], int parent[]) {
    visited[u] = 1;
    for (AdjList* p = graph.AdjList[u]; p != nullptr; p = p->next) {
        int v = p->adjVertex;
        if (!visited[v]) {
            parent[v] = u;
            DFSUtil(graph, v, visited, parent);
        }
    }
}

vector<int> pathNoVertex(AdjListGraph& g, int s, int d, int v) {
        vector<int> path;
        bool visited[MAX_VERTICES]= {false};
        path.push_back(s);
        visited[v] = true;
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (AdjList* p = g.AdjList[curr]; p!=nullptr; p=p->next)
            {
                if(!visited[p->adjVertex])
                {
                    visited[p->adjVertex] = true;
                    path.push_back(p->adjVertex);
                    q.push(p->adjVertex);
                }
            }
            
        }
        return path;
    }
vector<int> pathGreatThan(AdjListGraph g, int s, int d, int M)
{
        vector<int> path;
        bool visited[MAX_VERTICES]= {false};
        path.push_back(s);
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (AdjList* p = g.AdjList[curr]; p!=nullptr; p=p->next)
            {
                if(!visited[p->adjVertex] && p->weight >= M)
                {
                    visited[p->adjVertex] = true;
                    path.push_back(p->adjVertex);
                    q.push(p->adjVertex);
                }
            }
            
        }
        return path;
}

int main()
{
    AdjListGraph g;
    readGraphFromFile(g, "Graph4.txt");
    printGraph(g);  
    int parent[MAX_VERTICES] = {-1};
    // PathBFS(g, 0, parent);
    // cout << "Path from 4 to 6" << endl;
    // printPath(parent, 0, 1);
    for(int i : pathNoVertex(g, 1, 0 , 5))
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i : pathNoVertex(g, 1, 0, 20))
    {
        cout << i << " ";
    }
    cout << endl;
//     0 1
// 1 2
// 0 3
// 3 4
// 2 3
// 4 2
// 5 0
// 5 1
// 3 1
// 2 0
// 5 6
}