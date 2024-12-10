#include <bits/stdc++.h>
using namespace std;
int m, n, u;
void inSoBac(vector <vector <int>> graph )
{
    for (int i = 1; i <= n; i++)
    {
        //cout << i << endl;
        cout << graph[i].size() << " ";
    }
    cout << "\n";
}
vector <bool> visitedDFS;
void BFS(vector <vector <int>> graph, int x)
{
    vector <bool> visitedBFS(n+1, false);
    queue <int> point;
    point.push(x);
    visitedBFS[x] = true;
    while (!point.empty())
    {
        int tmp = point.front();
        cout << tmp << " ";
        point.pop();
        for (int i : graph[tmp])
        {
            if (!visitedBFS[i])
            {
                point.push(i);
                visitedBFS[i] = true;
            }
        }
    }
}

void DFS( vector <vector <int>> graph, int x)
{
    visitedDFS[x] = true;
    cout << x << " ";
    for (int i : graph[x] )
    {
        if (!visitedDFS[i])
            DFS(graph, i);
    }
    //
}
void DFS_noprint( vector <vector <int>> graph, int x)
{
    visitedDFS[x] = true;
    //cout << x << " ";
    for (int i : graph[x] )
    {
        if (!visitedDFS[i])
            DFS(graph, i);
    }
    //
}
int DFS_find( vector <vector <int>> graph, int x,int dich, int dem)
{
    if (x == dich)
        return dem;
    visitedDFS[x] = true;
    cout << dem << " ";
    for (int i : graph[x] )
    {
        if (!visitedDFS[i])
        {
            visitedDFS[i] = true;
            return DFS_find(graph, i,dich, dem++);
        }
             
    }

}
int chuaTham()
{
    for (int i = 1; i <= n; i++ )
    {
        if (!visitedDFS[i])
            return i;
    }
    return -1;
}
int main()
{

    cin >> n >> m >> u;
    visitedDFS.resize(n +1, false);
    vector <vector <int>> graph;
    graph.resize(n +1);
    for (int i = 1; i <= n; i++)
    {
        graph[i].resize(0);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    inSoBac(graph);
    for (int i = 1; i <= n; i++)
    {
        DFS_find(graph, i, u, 0) ;
    }
    visitedDFS.resize(n +1, false);
    cout << "\n";
    BFS(graph, u);
    cout << "\n";
    DFS(graph, u);
    cout << "\n";
    int lienthong = 1;
    if (chuaTham() != -1)
    {
        lienthong++;
        DFS_noprint(graph,chuaTham() );
    }
    cout << lienthong << endl;


}