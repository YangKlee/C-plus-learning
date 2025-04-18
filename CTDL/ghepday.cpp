#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file(f) if (fopen(f".inp","r")) {freopen(f".inp","r",stdin); freopen(f".out","w",stdout);}
using namespace std;
vector<int> merge(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    vector <int> result;
    while (i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            result.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j])
        {
            result.push_back(b[j]);
            j++;
        }
        else
        {
            result.push_back(a[i]);
            result.push_back(b[j]);
            i++;
            j++;
        }
    }
    while(i < a.size())
    {
        result.push_back(a[i]);
        i++;
    }
    while(j < b.size())
    {
        result.push_back(b[j]);
        j++;
    }
    return result;
}
int main()
{
    IOS;
    int m, n;
    cin >> m >> n;
    vector<int> a, b;
    a.resize(m); b.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(int x : merge(a, b))
    {
        cout << x << " ";
    }
}