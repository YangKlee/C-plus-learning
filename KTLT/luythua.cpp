#include <bits/stdc++.h>
using namespace std;
unsigned long long int tinhLuyThua(long long a, long long n)
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
    cout.tie(NULL);
    unsigned long long int a,b;
    unsigned long long int k;
    cin >> a >> b >> k;
    a = a*tinhLuyThua(10,k);
    cout << (a/b)%10;
}