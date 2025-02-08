#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
int dp[100001];
void debug(vti t)
{
    for (int i = 0; i <= t.size(); i++)
    {
        cout << dp[i] << " ";
    }
    el;
}
int tgNhoNhat(vti t, vti r)
{
    dp[0] = 0;
    dp[1] = t[1];
    for (int i = 2; i < t.size(); i++)
    {
        dp[i] = min(dp[i-1]+t[i], dp[i-2] + r[i-1]);
        //cout << i << " "<< r[i-1] << endl;
    }
    //debug(t);
    return dp[t.size()-1];
}
int main()
{
    int n;
    cin >> n;
    vti t(n+1);
    vti r(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n-1; i++)
    {
        cin >> r[i];
    }
    cout << tgNhoNhat(t,r);

}