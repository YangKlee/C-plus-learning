#include<bits/stdc++.h>
#define ll long long
#define inp(n) cin >> n
#define out(n) cout << n;
#define loop(i,a,b) for(int i = a; i <=b ; i++)
using namespace std;
int main()
{
    // tong tu 1 den n
    ll n, sum = 0;
    inp(n);
    loop(i,1,n)
    {
        sum+= i;
    }
    out(sum);
}