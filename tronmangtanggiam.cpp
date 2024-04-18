#include<bits/stdc++.h>
using namespace std;
vector <int> Merge(vector <int> a, vector <int> b)
{
    int index_a = 0, index_b = b.size()-1;
    vector <int> c;
    while(index_a < a.size() && index_b >=0)
    {
        if(a[index_a] <= b[index_b])
        {
            c.push_back(a[index_a]);
            index_a++;
        }
        else
        {
            c.push_back(b[index_b]);
            index_b--;
        }
    }
    while(index_a < a.size())
    {
        c.push_back(a[index_a]);
        index_a++;
    }
    while(index_b >=0)
    {
        c.push_back(b[index_b]);
        index_b--;
    }
    return c;
}
int main()
{
    int n, m;
    vector <int> a; // mang tang
    vector <int> b; // mang giam
    vector <int> c;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        int tmp; cin >> tmp;
        b.push_back(tmp);
    }
    c = Merge(a,b);
    for(int x:c)
    {
        cout << x << ' ';
    }
}