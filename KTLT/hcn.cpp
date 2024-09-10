#include <bits/stdc++.h>
using namespace std;
struct HCN{
    int d;
    int r;
}H1,H2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> H1.d >> H1.r >> H2.d >> H2.r;
    if( H1.d == H2.d || H1.r == H2.r || H1.d == H2.r ||H1.r == H2.d)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}