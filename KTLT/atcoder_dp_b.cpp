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
int n, k;

int main()
{
    IOS;
    cin >> n >> k;
    vti rock(n+1);
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> rock[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int min = INFINITY;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 1)
            {
                int tmp = dp[i - j] + abs(rock[i] - rock[i - j]);
                if (tmp < min)
                    min = tmp;
            }
            dp[i] = min;
        }
    }
    cout << dp[n];   

}