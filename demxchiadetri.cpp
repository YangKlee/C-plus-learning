#include<bits/stdc++.h>
using namespace std;
int DemX(vector <int>a, int l, int r, int x)
{
    if(l == r)
    {
        if(a[l] == x)
            return 1;
        return 0;
    }
    else
    {
        int m = (l+r)/2;
        return DemX(a,l,m,x) + DemX(a,m+1,r,x);
    }
}
int main()
{
    int n, x;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Nhap x: ";
    cin >> x;
    cout << DemX(a,0,n-1,x);

}