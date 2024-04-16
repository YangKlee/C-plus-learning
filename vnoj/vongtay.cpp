#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("vt.inp","r",stdin);
    freopen("vt.out","w",stdout);
    ll n;
    cin >> n;
    cout << n%7 << ' ' << 7-(n%7);  
}