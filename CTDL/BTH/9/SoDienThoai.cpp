#include <bits/stdc++.h>
using namespace std;
#define MAX_DINH 100
struct graph{
    bool ke[MAX_DINH][MAX_DINH]=  {false};
    int soDinh;
};
//Cho biết sinh viên x biết trực tiếp số điện thoại sinh viên y không?
bool isKnowPhone(graph g, int x, int y)
{
    return g.ke[x][y];
}
void test(graph g)
{
    for (int i = 0; i < g.soDinh; i++) {
        for (int j = 0; j < g.soDinh; j++) {
            cout << g.ke[i][j] << " ";
        }
        cout << endl;
    }
}
//Cho biết sinh viên x biết trực tiếp hoặc gián tiếp số điện thoại của sinh viên z không?
bool isKnowPhone2(graph g, int x, int z, bool visited[])
{
    visited[x] = true;
    if(x == z)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < g.soDinh; i++)
        {
            if(g.ke[x][i] != 0 && !visited[i])
            {
                return isKnowPhone2(g, i, z, visited);
            }
        }
    }
    return false;
}

//Cho biết sinh viên x có thể biết được số điện thoại hết cả lớp không?
bool isXKnowAllPhone(graph g, int x){
    // dung BFS
    queue<int> q;
    bool visited[MAX_DINH] = {false};
    q.push(x);
    visited[x] = true;
    while(!q.empty())
    {
            int vertex = q.front();
            // cout << vertex << " ";
            q.pop();
            for (int i = 0; i < g.soDinh; i++)
            {
                if(g.ke[vertex][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
    
                }
            }
    }
    for(int i = 0; i < g.soDinh; i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    // cout << endl;
    return true;

}
// Cho biết những sinh viên mà không ai biết số điện thoại.
vector<int> noOneKnowPhone(graph g)
{
    vector<int> list;
    for (int i = 0; i < g.soDinh; i++)
    {
        bool isKnow = false;
        for (int j = 0; j < g.soDinh; j++)
        {
            if(g.ke[j][i] != 0)
            {
                isKnow = true;
            }

        }
        if(!isKnow)
        {
            list.push_back(i);
        }
    }
    return list;
}
//Cho biết có sinh viên nào biết số điện thoại hết cả lớp không?
vector<int> whoKnowAllPhone(graph g)
{
    vector<int> result;
    for (int i = 0; i <g.soDinh; i++)
    {
        if(isXKnowAllPhone(g, i))
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
/*
test case 1
7 10
0 1
1 2
0 3
1 3
2 4
4 5
5 6
5 2
2 5
2 6

test case 2
9 11
0 1
1 2
0 3
1 3
2 4
4 5
5 6
5 2
2 5
2 6
7 8

*/


    graph g;
    int n, k;
    
    cin >> n >> k;
    
    g.soDinh = n;
    int u, v;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        g.ke[u][v] = true;
    }
    test(g);
    cout << isKnowPhone(g, 1, 6) << endl;
    bool visited[MAX_DINH] = {false};
    cout << isKnowPhone2(g, 1,5, visited) << endl;
    cout << isXKnowAllPhone(g, 0) << endl;
    cout << "Danh sach sinh vien khong ai biet so dien thoai" << endl;
    for(int x:noOneKnowPhone(g))
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Danh sach sinh vien biet tat ca so dien thoai ca lop" << endl;
    for(int x:whoKnowAllPhone(g))
    {
        cout << x << " ";
    }
    cout << endl;
}