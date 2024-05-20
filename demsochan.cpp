#include<bits/stdc++.h>
using namespace std;

int demsochan(vector <int> a, int l, int r)
{
    if(l >r)
        return 0;
    else if(l == r)
    {
        if(a[l]%2 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int m = (l+r)/2;
        return demsochan(a,l,m) + demsochan(a, m+1, r);
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
    cout << demsochan(a,0,a.size()-1);
}