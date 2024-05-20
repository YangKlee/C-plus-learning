#include<bits/stdc++.h>
using namespace std;

int find_i(vector <int> a, int l, int r)
{
    if(l>r)
        return -1;
    else
    {
        int m = (l+r)/2;
        if(a[m] == m)
            return m;
        else if(a[m] > m )
            return find_i(a,l,m-1);
        else if(a[m] < m)
            return find_i(a,m+1,r);
    }
}
int main()
{
    vector <int> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        a.push_back(k);
    }
    cout << find_i(a,0,a.size()-1);
}