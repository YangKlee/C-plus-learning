#include<bits/stdc++.h>
using namespace std;
int GetMax(vector <int> a, int l, int r)
{
    if(l >= r)
    {
        return a[l];
    }
    else
    {
        int m = (l+r)/2;
        if(GetMax(a,l,m) >= GetMax(a,m+1,r))
        {
            return GetMax(a,l,m);
        }
        else
            return GetMax(a,m+1,r);
    }
}
int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << GetMax(a,0, a.size()-1);
}