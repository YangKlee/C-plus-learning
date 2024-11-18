#include <bits/stdc++.h>
using namespace std;
long long jump(int n, vector <int> h, vector <long long> cost)
{
    cost[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cost[i] = (long long)min(cost[i-1] + abs(h[i] - h[i-1]), cost[i-2] + abs(h[i] - h[i-2]));
    }
    return cost[n];
}
int main()
{
    int n;
    cin >> n;
    vector <int> h(n+1);
    vector <long long> cost(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        cost[i] = 0;
    }
    cout << jump(n, h, cost);
}