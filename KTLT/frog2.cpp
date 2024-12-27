#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
long long dp[101][100001];
int fogJump(vti hRock, int n, int k)
{
    // inilazie
    for (int i =1; i <= k; i++)
    {
        dp[i][1] = 0;
        //dp[i][2] = abs(hRock[1] - hRock[0]);
    }
    for (int i = 2; i <= n; i++)
    {
        dp[1][i] = dp[1][i-1]+ abs(hRock[i] - hRock[i-1]);
    }
    // i la gioi han nhay - j la da thu j
    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            
            if (j >= i +1)
            {
                //dp[i][j] = min(abs(hRock[j] - hRock[j - i]) + dp[i-1][j - i], dp[i-1][j-1] + abs(hRock[j] - hRock[j - i]) );
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[k][n];
}
int main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    vti hRock(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> hRock[i];
    }
    cout << fogJump(hRock, n, k);
}
