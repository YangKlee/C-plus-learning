#include<bits/stdc++.h>
using namespace std;
vector <int> tronmang(vector <int>a, vector <int> b,vector <int> c, int index_a, int index_b)
{
    //cout << index_a << ' ' << index_b << endl;
    if(index_a == a.size() && index_b != 0) // mang b chua duyet het
    {
        for(int i = index_b-1; i >= 0; i--)
        {
            c.push_back(b[i]);
        }
        return c;
    }
    else if(index_b == 0 && index_a != a.size()) // mang a chua duoc duyet het
    {
        for(int i = index_a; i < a.size(); i++)
        {
            c.push_back(a[i]);
        }
        return c;
    }
    else if(index_b == 0 && index_a == a.size())
    {
        return c;
    }
    else
    {
        if(a[index_a] <= b[index_b-1])
        {
            c.push_back(a[index_a]);
            return tronmang(a,b,c,index_a+1,index_b);
        }
        else
        {
            c.push_back(b[index_b-1]);
            return tronmang(a,b,c,index_a,index_b-1);
        }
    }
    
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector <int> a;
    vector <int> b;
    vector <int> c;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    c = tronmang(a,b,c,0,b.size());
    for(int x:c)
    {
        cout << x << ' ';
    }
    
}