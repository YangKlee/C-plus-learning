#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << (int)((log(b*1.0) - log(a*1.0))/log(2.0));
}
