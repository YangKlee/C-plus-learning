#include <bits/stdc++.h>
using namespace std;
long long tinhLuyThua(long long a, long long n)
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
    double a,b;
    long long int k;
    cin >> a >> b >> k;

    double result = a/b;
    std::setprecision(100000);
    //cout << result * pow(10,k);
    cout << (long long)(result*tinhLuyThua(10,k))%10;
}