#include <bits/stdc++.h>
#define MAX_VERTICES 100
using namespace std;
// bieu dien do thi bang ma tran ke
struct AdjMatrixGraph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};
void readGraphFromFile(string fileName, AdjMatrixGraph &graph)
{
    ifstream file(fileName);
    file >> graph.numVertices;
    for(int i = 0; i < graph.numVertices; i++)
    {
        for (int j = 0; j < graph.numVertices; j++)
        {
            file >> graph.adjMatrix[i][j];
        }
    }
    file.close();
}
void printGraph(AdjMatrixGraph graph)
{
    cout << "So dinh " << graph.numVertices << endl;
    for(int i = 0; i < graph.numVertices; i++)
    {
        for (int j = 0; j < graph.numVertices; j++)
        {
            cout << graph.adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void DFS(const AdjMatrixGraph &graph, int start, bool visited[])
{
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < graph.numVertices ; i++)
    {
        if(graph.adjMatrix[i][start] != 0 && !visited[i])
        {
            DFS(graph, i, visited); 
        }
    }
    
}
// duyet tat ca cac dinh
void traverseGraph(AdjMatrixGraph g)
{
    bool visited[MAX_VERTICES] = {false};
    for (int i = 0; i < g.numVertices; i++)
    {
        if(!visited[i])
        {
            DFS(g, i, visited);
        }
    }
}
void BFS(const AdjMatrixGraph &graph, int vertex)
{
    queue<int> q;
    bool visited[MAX_VERTICES] = {false};
    visited[vertex] = true;
    q.push(vertex);
    while(!q.empty())
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (int i = 0; i < graph.numVertices; i++)
        {
            if(graph.adjMatrix[curr][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

}
// đếm số cạnh
int countEdges(AdjMatrixGraph g)
{
    int count = 0;
    for (int i = 0; i < g.numVertices; i++)
    {
        for (int j = i+1; j < g.numVertices; j++)
        {
            if(g.adjMatrix[i][j] != 0)
            {
                count++;
            }
        }
    }

    return count;
}
//Viết hàm tính số cạnh vào đỉnh x với đồ thị có hướng, không có trọng số.
int countIncomingEdges(AdjMatrixGraph g, int x)
{
    int count = 0;
    for (int i = 0; i < g.numVertices; i++)
    {
        if(g.adjMatrix[i][4] !=0)
        {
            count++;
        }
    }
    return count;
}
//Viết hàm liệt kê những đỉnh không kề với đỉnh x
void notAdjacent(AdjMatrixGraph g, int x)
{
    bool isKe[MAX_VERTICES] = {false};
    isKe[x] = true;
    for (int i = 0; i < g.numVertices; i++)
    {
        if(g.adjMatrix[i][x] != 0)
        {
            isKe[i] = true;
        }
    }
    for(int i = 0; i < g.numVertices; i++)
    {
        if(!isKe[i] )
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
//Viết hàm liệt kê những đỉnh không thăm được khi duyệt xuất phát từ đỉnh x
void notVisited(AdjMatrixGraph g, int x)
{
    bool visited[MAX_VERTICES] = {false};
    DFS(g, x, visited);
    for (int i = 0; i < g.numVertices; i++)
    {
        if(!visited[i] )
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
//Kiểm tra một dãy các đỉnh có là đường đi của đồ thị không?
bool isPath(AdjMatrixGraph g, int arr[], int k){

    for (int i = 0; i < k - 1; i++)  
    {
        if (g.adjMatrix[arr[i]][arr[i + 1]] == 0)
        {
            return false;  
        }
    }
    return true;  
}
int main()
{
    AdjMatrixGraph graph;
    readGraphFromFile("Graph2.txt", graph);
    printGraph(graph);
    bool visited[MAX_VERTICES] = {false};
    DFS(graph, 4, visited);
    cout << endl;
    BFS(graph, 0);
    cout << endl;
    traverseGraph(graph);
    cout << endl;
    cout << "So canh cua do thi la: " << countEdges(graph) << endl;
    notAdjacent(graph, 6);
    int path[5] ={0, 5, 4, 2, 3};
    cout << isPath(graph, path, 5);
}