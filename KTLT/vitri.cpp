#include <bits/stdc++.h>
using namespace std;
int searchBinary(vector <int> a, int l, int r, int x, int pos)
{
    if (a[a.size() - 1] < x || a[0] > x)
        return -1;
    if (l > r)
        return pos;
    else
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            pos = m;
            return searchBinary(a, l, m-1, x, pos);
        }
        else if (a[m] > x)
        {
            return searchBinary(a, l, m-1, x, pos);
        }
        else 
        {
            return searchBinary(a, m+1, r, x, pos);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++)
    {
        int tmp;
        cin >> tmp;
        int pos = searchBinary(a, 0, n-1, tmp, -1);
        if (pos == -1)
            cout << pos << endl;
        else
            cout << pos+1 << endl;
        // query
    }
}