#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    long long a,b;
    a = 0;
    b = 1;
    for (int i = 2; i <= n; i++)
    {
        long long c = a+b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n; cin >> n;
    cout << fibo(n);

}