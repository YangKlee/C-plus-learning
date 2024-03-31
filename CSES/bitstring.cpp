#include <bits/stdc++.h>
const long long modulo = 1e9+ 7LL;

using namespace std;
unsigned long long binary_arr(int n)
{
    long long x = 1LL;
    for(int i = 1; i <= n; i++)
    {
        x = (x * 2)%modulo;
    }
    return x;
}
int main()
{
    int n;
    cin >> n;
    cout << binary_arr(n%modulo);
}