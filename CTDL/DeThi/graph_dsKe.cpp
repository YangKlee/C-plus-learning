#include <bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 100
struct AdjList
{ 
    int adjVertex; 
    float weight;
    AdjList* next;
};
struct AdjListGraph {
    int numVertices;
    AdjList* adjList[MAX_VERTICES]; 
};
void insertAdjList(AdjList* &root, int vertex)
{
    AdjList* newNode = new AdjList();
    newNode->adjVertex = vertex;
        // nếu có trọng số thì gán bằng trọng số
    newNode->weight = 0;
    newNode->next = nullptr;
    if(root == nullptr)
    {
        root = newNode;
    }
    else
    {
        AdjList* p = root;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        if(p->next == nullptr)
        {
            p->next = newNode;
        }
    }
}
// vd này dành cho đồ thị k có trọng số nha
void readFile(string filename, AdjListGraph &graph)
{
    ifstream f(filename);
    // đọc dòng đầu tiên chứa số đỉnh của đồ thị
    string line;
    getline(f, line);                      // đọc dòng đầu tiên
    graph.numVertices = stoi(line);       // chuyển thành int
    // khởi tạo danh sách rỗng
    for (int i = 0; i < graph.numVertices; ++i) {
        graph.adjList[i] = nullptr;
    }
    string rawData;

        // dùng stringstream xử lý từng dòng
    // bỏ xuống dòng
    while(getline(f, rawData))
    {
        // khởi tạo node
        
        stringstream ss(rawData);
        int vertex;
        // xử lý từng cột
        int i ;
        ss >> i;

        while (ss >> vertex)
        {
            insertAdjList(graph.adjList[i], vertex);
        }

    }
    f.close();
}
void BFS(AdjListGraph g, int v) {
    queue<int> q; 
    int u;

    // Dùng mảng visited để tránh duyệt lại đỉnh đã thăm
    bool visited[g.numVertices] = {false};

    // Đưa đỉnh bắt đầu vào hàng đợi
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        u = q.front(); 
        q.pop();

        // Xử lý đỉnh đang duyệt (in ra)
        cout << u << " ";

        // Duyệt tất cả đỉnh kề với u
        AdjList* p = g.adjList[u];
        while (p != nullptr) {
            int w = p->adjVertex;
            if (!visited[w]) {
                q.push(w);
                visited[w] = true;
            }
            p = p->next;
        }
    }
}
void DFS(AdjListGraph g, int v, bool visited[])
{
    visited[v] = true;
    AdjList* p = g.adjList[v];
    cout << v << " ";
    while (p != nullptr)
    {
        if (!visited[p->adjVertex])
            DFS(g, p->adjVertex, visited);
        p = p->next;
    }
}

int main()
{
    AdjListGraph graph;
    readFile("dske.txt", graph);
    bool visited[MAX_VERTICES] = {false};
    DFS(graph, 1, visited);
    BFS(graph, 1);
}
