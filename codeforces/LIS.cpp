#include <bits/stdc++.h>
using namespace std;
int LIS(vector <int> a, vector <int> l)
{
    l[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                l[i] = max(l[i], l[j] +1);
            }
        }
    }
    int max_l = 0;
    for (int i = 0; i < l.size(); i++)
    {
        if(l[i] > max_l)
            max_l = l[i];
    }
    return max_l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l[i] = 0;
    }
    cout << LIS(a, l);
}