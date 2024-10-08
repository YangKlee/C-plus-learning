#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <long long> a(n);
    vector <long long> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        long long tmp; cin >> tmp;
        a[i] = tmp;
        if(i == 0)
            dp[0] = tmp;
        else
        {
            for (int j =  i-1; j >= 0; j--)
            {
                dp[i] = max(a[i]*a[j], max(dp[i], dp[i-1]));
            }
        }

    }
    cout << dp[n-1];
}