#include <bits/stdc++.h>
using namespace std;
long long tinhGiaiThua(long long n)
{
    if(n == 1)
        return 1;
    else
        return n * tinhGiaiThua(n-1);
}
int main()
{
    long long n;
    cin >> n;
    cout << tinhGiaiThua(n);
}