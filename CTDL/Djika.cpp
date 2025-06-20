#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX_DINH 100
#define INF (int)1e9
using namespace std;


struct graph{
    ll adj[MAX_DINH][MAX_DINH] = {INF};
    int num;
};
struct Node{
    float distance;
    int vertex;
    bool operator<(const Node& other) const{
        return distance > other.distance;
    }

};
void Dijkstra(graph g, int s, ll dist[], ll parent[])
{
    priority_queue<Node> q;
    bool visited[MAX_DINH] = {false};
    for (int i = 0; i < g.num; i++)
    {
        dist[i] = g.adj[s][i];
        parent[i] = s;
    }
    dist[s] = 0;
    // S = {s}
    q.push({dist[s], s});
    //     Mỗi vòng lặp chọn ra đỉnh gần nhất chưa duyệt.
    // Đảm bảo không xử lý lại đỉnh đã duyệt (giúp tránh vòng lặp vô hạn).
    // Chuẩn bị để sau đó cập nhật khoảng cách cho các đỉnh kề của u₀.
    int k = 0;
    while (k < g.num)
    {
        Node minNode = q.top();
        q.pop();
        int u0 = minNode.vertex;
        if(visited[u0])
        {
            continue;
        }
        visited[u0] = true;
        k++;
        for (int v = 0; v < g.num; i++)
        {
            if(!visited[v] && g.adj[u0][v] != INF &&)
        }

    }
    

}
int main()
{
    graph g;
    int n, q;
    cin >> n >> q;
    g.num = n;
    for (int i = 0; i < q; i++)
    {
        int u,v,k;
        cin >> u >> v >> k;
        g.adj[u][v] = k;
    }
}