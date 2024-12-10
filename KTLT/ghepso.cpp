#include <bits/stdc++.h>
#define ll long long
using namespace std;
string daySo = "";
void genDonVi(ll n)
{
    for (ll i = n; i > 0; i--)
    {
        daySo += to_string(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    genDonVi(n);
    cout << daySo;
    
}