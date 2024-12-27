#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
void debugArray(vtll a)
{
    for (ll x: a)
        cout << x << " ";
    el;
}
int firstBinarySearch(vtll a, int l, int r, int x)
{
    //debugArray(a);
    if (l > r)
        return 0;
    else
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            return 1 + firstBinarySearch(a, l, m-1, x);
        }
        else if (a[m] > x)
             return firstBinarySearch(a, l, m-1, x);
        else
            return firstBinarySearch(a, m+1, r, x);
    }
}
int main()
{
    IOS;
    bool isUseFile = 0;
    if (isUseFile == 1)
    {
        freopen("socap.inp","r",stdin);
        freopen("socap.out","w",stdout);
    }
    ll n, x;
    cin >> n >> x;
    vtll a;
    //a.resize(n);
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        ll pbu = x - a[i];
        if (a[i+1] <= pbu && pbu <= a[n -1])
        {
            if (firstBinarySearch(a,  i +1, n -1 , pbu  ) != 0)
                dem+= firstBinarySearch(a,  i +1, n -1 , pbu  );
        }
    }
    cout << dem << endl;
    // code here
}