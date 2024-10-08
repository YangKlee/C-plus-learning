#include <bits/stdc++.h>
using namespace std;
long long tinhLuyThua(long long a ,int n)
{
    if (n == 0)
        return 1;
    else
    {
        if (n % 2 == 1)
            return tinhLuyThua(a, n/2) * tinhLuyThua (a , n/2) * a ;
        else
            return tinhLuyThua(a , n/2) * tinhLuyThua (a ,n/2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    while (cin >> n)
    {
        if(n == 0)
            break;
        cout << tinhLuyThua(n, 4) << '\n';
    }
}