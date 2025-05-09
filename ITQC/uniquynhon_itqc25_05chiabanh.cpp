#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define iny long long
using namespace std;
int dp[100001][3];
int main()
{
    IOS;
    int n;
    cin >> n;
    // C(n-1) 2
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, 2); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1; 
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
        }
    }
    cout << dp[n-1][2];

}