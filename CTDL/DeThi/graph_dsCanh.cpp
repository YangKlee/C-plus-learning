#include <bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 100
#define MAX_EDGES 100
struct Edge
{
    int startVertex, destVertex;
    float weight; 
};
struct EdgeListGraph
{
    int numVertices, numEdges;
    Edge edgeList[MAX_EDGES]; 
};
void readFile(string filename, EdgeListGraph &graph)
{
    ifstream f(filename);
    // đọc dòng đầu tiên chứa số đỉnh của đồ thị
    f >> graph.numVertices;
    // đọc lấy số cạnh
    f >> graph.numEdges;
    // duyệt từng dòng tiếp theo của file
    for (int i = 0; i < graph.numEdges; i++)
    {
        Edge newEdge;
        f >> newEdge.startVertex;
        f >> newEdge.destVertex;
        // nếu đồ thị không có trọng số thì bỏ
        // f >> newEdge.weight;
        graph.edgeList[i] = newEdge;
    }
    f.close();
}
void DFS(EdgeListGraph g, int v, bool visited[])
{
    visited[v] = true; // đánh dấu đỉnh v là đã thăm
    // Duyệt tất cả các cạnh trong danh sách cạnh
    cout << v << " ";
    for (int i = 0; i < g.numEdges; i++)
    {
        // Nếu cạnh bắt đầu từ đỉnh v
        if (g.edgeList[i].startVertex == v)
        {
            // lấy đỉnh kết thúc của cạnh
            int w = g.edgeList[i].destVertex;
            // nếu đỉnh w chưa được thăm thì tiếp tục DFS từ w
            if (!visited[w])
                DFS(g, w, visited);
        }
    }
}
void BFS(EdgeListGraph g, int start)
{
    bool visited[MAX_VERTICES] = {false}; // đánh dấu các đỉnh đã duyệt
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " "; // xử lý đỉnh v

        // Duyệt toàn bộ danh sách cạnh để tìm đỉnh kề v
        for (int i = 0; i < g.numEdges; i++)
        {
            if (g.edgeList[i].startVertex == v)
            {
                int w = g.edgeList[i].destVertex;
                if (!visited[w])
                {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }
}

int main()
{
    EdgeListGraph graph;
    readFile("dscanh.txt", graph);
    bool visited[MAX_VERTICES] = {false};
    DFS(graph, 1, visited);
    BFS(graph, 1);
}