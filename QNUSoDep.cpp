#include <bits/stdc++.h>
using namespace std;
long long get_sum(long long n)
{
    if(n == 0)
        return 0;
    else
        return 1LL * n%10+get_sum(n/10);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if(get_sum(n)%10 == 9)
        cout << "DEP";
    else
        cout << "KHONGDEP"; 
}