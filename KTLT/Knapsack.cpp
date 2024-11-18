#include <bits/stdc++.h>
using namespace std;
long long dp[101][1000001];
long long knapsack(int n ,int w_max, vector <int> kl, vector <int> gt)
{
    // khoi tao
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= w_max; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w_max; j++)
        {
            if (kl[i] <= j)
            {
                dp[i][j] = (long long)max(dp[i-1][j], dp[i-1][j - kl[i]] + gt[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w_max];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n >> w;
    vector <int> kl(n+1);
    vector <int> gt(n+1);
    for (int i = 1; i <=n; i++)
    {
        cin >> kl[i] >> gt[i];
    }
    cout << knapsack(n, w, kl, gt);
}