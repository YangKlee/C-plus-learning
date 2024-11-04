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
    long long n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    for (int j = 0; j < a.size(); j++)
    {
        // ai = x - aj
        long long phanbu = x - a[j];
        int pos = timKiem(a, 0, a.size() -1, phanbu);
        
        if (pos != j && pos != -1)
        {
            //cout << a[j] << " " << a[pos] << endl;
            a.erase(a.begin() + j);
            a.erase(a.begin() + pos);
            //temp.insert(make_pair(j, pos));
            count++;
        }
    }
    cout << count;
}