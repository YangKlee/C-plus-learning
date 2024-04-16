#include<bits/stdc++.h>
#define ll long long
#define loop(i,a,b) for(ll i = a; i <=b ; i++)
using namespace std;
int main()
{
    //freopen("nt.inp","r",stdin);
    //freopen("nt.out","w",stdout);
    ll n;
    cin >> n;

    loop(i,2,sqrt(n))
    {
        if(n%i == 0)
        {
            cout << "NO" ;
            exit(0);
        }
    }
    cout << "YES";
}