
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
using namespace std;
bool graph[100000+1][100000+1] = {false};
int findPath(int n, int start, int end)
{
    queue<int> tmp;
    bool visited[n+1] = {false};
    tmp.push(start);
    visited[start] = true;
    int hop = 0;
    // int soDinh = 1;
    while (!tmp.empty())
    {
        int soDinhHienTai = tmp.size();
        // soDinh = 0;

        for (int j = 0; j < soDinhHienTai; j++)
        {
            int tham = tmp.front();
            // visited[tham] = 1;
            // cout << tham << " ";
            tmp.pop();
            if(tham == end)
            {
                return hop;
            }
            
            for (int i = 1; i <= n; i++)
            {
                if(!visited[i] && graph[tham][i])
                {   
                    visited[i] = true;
                    tmp.push(i);
                }
            }
        }
        hop++;
        
    }
    return -1;
    
}
int main()
{
    IOS;
    int n, t, u, v, s;
    cin >> n >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = true;

    }
    cin >> s >> t;
    cout << findPath(n, s, t);
}   