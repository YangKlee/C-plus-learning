#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
ull MOD = 1000000007;
using namespace std;
int giaiThua(int n)
{
    ull res= 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res * (ull)i) % MOD ;

    }
    //cout << res;
    return res;
}
ull tinhToHop(ull k, ull n)
{   
    return ((ull)(giaiThua(n)) / (ull)(giaiThua(k) * (ull)giaiThua(n-k))) % MOD;
    //return giaiThua(5);
}
int main()
{
    IOS;
    ull n, k;
    cin >> n >> k;
    ull count = 0;
    for (int i = 0; i < n; i++)
    {
        ull a;
        cin >> a;
        count += tinhToHop(a, k);
    }
    cout << count;
}