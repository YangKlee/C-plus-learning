#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file(f) if (fopen(f".inp","r")) {freopen(f".inp","r",stdin); freopen(f".out","w",stdout);}
#define ll long long
using namespace std;
int main()
{
    IOS;
    int n, q, p, u, v, k;
    cin >> n >> q >> p;
    vector <int> a(n, 0);
    vector<ll> diff(n + 2, 0); 

    for (int i = 0; i < q; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;  
        diff[u] += k;
        diff[v + 1] -= k;
    }
    a[0] = diff[0];
    for (int i = 1; i < n; ++i) {
        a[i] = a[i - 1] + diff[i];
    }

    vector <ll> prefix(n, 0);
    prefix[0] = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        prefix[i] = prefix[i-1] + (ll)a[i]; 
    }
    // for (int x: a)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    for (int i = 0; i < p; i++)
    {
        cin >> u >> v;
        u--;v--; 
        ll sum = 0;
            if(u!= 0)
                sum = prefix[v] - prefix[u-1];
            else
                sum = prefix[v];
        cout << sum << endl;
    }

}