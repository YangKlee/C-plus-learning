#include <bits/stdc++.h>
using namespace std;
long long tinhLuyThua(long long a, long long b)
{
    if(b == 1 || b == -1)
        return a;
    else
    {
        if(b % 2 == 0)
            return tinhLuyThua(a,(b /2ll)) * tinhLuyThua(a,(b /2ll));
        else
            return tinhLuyThua(a, (b /2ll)) * tinhLuyThua(a,(b /2ll)) *a;
    }

}
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << tinhLuyThua(a,b) % c;
}