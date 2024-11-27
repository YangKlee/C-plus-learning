#include <bits/stdc++.h>
#define long long int;
using namespace std;

int searchBinary(vector <int> a, int l, int r, int x, int pos)
{
    if (l > r)
        return pos;
    else
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            pos = m;
            return pos;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // ai = x - aj
    int range;
    if ((n - 1) %2 == 0)
        range = (n-1)/2;
    else
        range = ((n-1)/2) +1;
    int dem = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < range; i++)
    {
        
        int pos;
        int pbu = x - a[i];
        if (pbu < a[range] || pbu > a[n -1])
            pos = -1;
        else
            pos = searchBinary(a, range , n - 1, pbu, -1);
        if (pos != -1)
        {
            
            dem++;
        }

    }
    cout << dem << endl;
}