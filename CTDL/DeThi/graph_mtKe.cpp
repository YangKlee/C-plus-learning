#include <bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 100

struct AdjMatrixGraph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void readFile(string filename, AdjMatrixGraph &graph)
{
    ifstream f(filename);
    // đọc dòng đầu tiên chứa số đỉnh của đồ thị
    f >> graph.numVertices;
    // duyệt từng dòng tiếp theo của file
    for (int i = 0; i < graph.numVertices; i++)
    {
        // duyệt lần lượt từng cột của hàng
        for (int j = 0; j < graph.numVertices; j++)
        {
            f >> graph.adjMatrix[i][j];
        }
    }
    f.close();
}
void DFS(AdjMatrixGraph g, int start, bool visited[])
{
    visited[start] = true;
    // xử lý khi duyệt
    cout << start << " ";
    for (int i = 0; i < g.numVertices; i++)
    {
        // nếu là đồ thị có trọng số thì thay g.adjMatrix[start][i] == INF
        if(g.adjMatrix[start][i] ==  1 && !visited[i])
        {
            DFS(g, i, visited);
        }
    }
}
void BFS(AdjMatrixGraph g, int start)
{
    // dùng hàng đợi để quản lý thứ tự duyệt theo chiều rộng
    queue<int> q; 
    int u;
     // mảng visited đánh dấu các đỉnh đã thăm, khởi tạo tất cả là false
    bool visited[ g.numVertices] = {false};
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        u =q.front(); q.pop();
        // xử lý thăm
        cout << u << " ";
         // duyệt qua tất cả đỉnh kề với u
        for (int i = 0; i < g.numVertices; i++)
        {
             // nếu có cạnh từ u đến i (trong đồ thị không trọng số, giá trị là 1)
            // và đỉnh i chưa được thăm
            if(g.adjMatrix[u][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void DFSPath(AdjMatrixGraph g, int v, bool visited[], int parent[])
{
    visited[v] = true;
    for (int w = 0; w < g.numVertices; w++)
    {
        // Nếu có cạnh và đỉnh w chưa được thăm
        if (g.adjMatrix[v][w] == 1 && !visited[w])
        {
            parent[w] = v;             // ghi nhận v là cha của w
            DFSPath(g, w, visited, parent);
        }
    }
}
void path(AdjMatrixGraph g, int s, bool visited[], int parent[])
{
    // Khởi tạo visited và parent cho tất cả các đỉnh
    for (int i = 0; i < g.numVertices; i++)
    {
        visited[i] = false;
        parent[i] = -1; // -1 nghĩa là chưa có cha
    }

    // Gọi DFS từ đỉnh s
    DFSPath(g, s, visited, parent);
}


void printPath(int s, int d, int parent[])
{
    int z = d;
    while (z != s)
    {
        cout << z << " <== ";
        z = parent[z];
    }
    cout << s << endl;
}


int main()
{
    AdjMatrixGraph graph;
    readFile("mtke.txt", graph);
    bool visited[MAX_VERTICES] = {false};
    DFS(graph, 1, visited);
        int start = 1;
    int end = 6;
    int parent[MAX_VERTICES];
    visited[MAX_VERTICES] = {false};
    path(graph, start, visited, parent);
    cout << "Duong di tu " << start << " den " << end << " la: ";
    printPath(start, end, parent);
}