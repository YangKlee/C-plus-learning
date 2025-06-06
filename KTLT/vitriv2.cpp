#include <bits/stdc++.h>
using namespace std;
int timKiem(vector <int> a, int l, int r, int x)
{
    if (l > r)
    {
        return -1;
    }
    else 
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            return  m;
        }
        else
        {
            if (x < a[m])
                return timKiem(a, l, m-1, x);
            else
                return timKiem(a,m+1, r, x);
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
        int x; cin >> x;
        cout << find(a.begin(), a.end(), x);
    }
}