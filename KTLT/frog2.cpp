#include <bits/stdc++.h>
using namespace std;
long long dp[101][100001];
long long jump(int n, int k,  vector <long long> h )
{
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = (long long)min(dp[i-1][j-1] + abs(h[i] - h[i-1]), dp[i][j-1] + abs(abs(h[i] - h[i-1])));
        }
        
    }
    return dp[k][n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector <long long> h(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    cout << jump(n, k, h);
}