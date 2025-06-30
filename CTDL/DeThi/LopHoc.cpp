#include <bits/stdc++.h>
using namespace std;
#define MAX_DINH 100
struct AdjList
{
    int adjVertex;
    AdjList* next;
};
struct AdjListGraph{
    int numVertices;
    AdjList* adjList[MAX_DINH];
};
// add mot dinh ke voi vertex
void addVertex(AdjListGraph &g, int vertex, int ke)
{
    AdjList* nodeVertex = g.adjList[vertex];
    AdjList* newNode = new AdjList();
    newNode->adjVertex = ke;
    newNode->next = nullptr;
    if(nodeVertex == nullptr)
    {
        g.adjList[vertex] = newNode;
    }
    else
    {
        while(nodeVertex->next != nullptr)
        {
            nodeVertex = nodeVertex->next;
        }
        nodeVertex->next = newNode;
    }


}
void initGraph(AdjListGraph &g)
{
    g.numVertices = 8;
    for (int i = 0; i < g.numVertices; i++)
    {
        g.adjList[i] = nullptr;
    }
    addVertex(g,1, 0);
    addVertex(g,2, 4);
    addVertex(g,2, 7);
    addVertex(g,3, 1);
    addVertex(g,5, 2);
    addVertex(g,5, 0);
    addVertex(g,6, 8);
    addVertex(g,6, 3);
    addVertex(g,6, 5);
    addVertex(g,7, 8);
    addVertex(g,7, 6);
    addVertex(g,7, 5);
    cout << "OK" << endl;
}
void debugTest(AdjListGraph g)
{
    for (int i = 0; i < g.numVertices; i++)
    {
        for (AdjList* j = g.adjList[i]; j != nullptr; j = j->next)
        {
            cout << j->adjVertex << " " ;
        }
    }
}
// liet ke nhung sinh vien ma sinh vien  biet nha truc tiep
void lietKeBietNha(AdjListGraph g, int k)
{
    cout << "Danh sach nhung sinh vien ma sinh vien " << k << " biet nha truc tiep" << endl;

    for (AdjList* i = g.adjList[k]; i != nullptr; i = i->next)
    {
        cout << i->adjVertex << " " ;
    }
    cout << endl;
}
void DFSPath(AdjListGraph g, int v, bool visited[], int parent[])
{
    visited[v] = true;
    for (AdjList* p = g.adjList[v]; p != nullptr; p = p->next)
    {
        int w = p->adjVertex;
        if(!visited[w])
        {
            parent[w] = v;
            DFSPath(g, w, visited, parent);
        }
    }
}
void BFSPath(AdjListGraph g, int v, bool visited[], int parent[])
{
    queue<int> q;
    visited[v] = true;
    parent[v] = -1;
    q.push(v);
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        for (AdjList* i = g.adjList[x]; i != nullptr; i = i->next)
        {
            int vertex = i->adjVertex;
            if(!visited[vertex])
            {
                visited[vertex] = true;
                parent[vertex] = x;
                q.push(vertex);
            }
        }
    }
}
void printPath(int s, int d, int parent[])
{
    if (parent[d] == -1)
    {
        cout << "Khong co duong di tu " << s << " den " << d << endl;
        return;
    }
    vector <int> path;
    int z = d;
    while (z != s)
    {

        path.push_back(z);
        z= parent[z];
    }
    path.push_back(s);
    cout << "Di qua it nhat " << path.size()-2 << " sinh vien trung gian" << endl;
}
void path(AdjListGraph g, int s,int d, bool visited[], int parent[])
{
    for (int i = 0; i < g.numVertices; i++)
    {
        visited[i] = false;
        parent[i] = -1;

    }
    BFSPath(g, s, visited, parent);
    printPath(s, d, parent);
}

int main()
{
    AdjListGraph g;
    initGraph(g);
    //debugTest(g);
    lietKeBietNha(g,3);
    bool visited[MAX_DINH];
    int parent[MAX_DINH];
    path(g, 6, 4,visited, parent);

    return 0;
}
