#include <bits/stdc++.h>
using namespace std;
void inSoNguoc(long long n)
{
    if (n < 10)
    {
        if (n != 0)
            cout << n;
        return;
    }
    else
    {
        cout << n%10;
        inSoNguoc(n/10);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b;
    cin >> a  >> b;
    inSoNguoc(a+b);
}