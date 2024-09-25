#include <bits/stdc++.h>
using namespace std;
long long tinhLuyThua(long long a, long long b, long long c)
{
    long long tmp = (long long)1;
    for (int i = 0; i < b; i++)
    {
        tmp =  (tmp * a) % c;
    }
    return tmp;
}
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << tinhLuyThua(a,b, c) ;
}