#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, count = 0;
    long long money;
    cin >> n >> money;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a[i] = tmp;
    }
    sort(a.begin(), a.end(), greater<>());
    int i = 0;
    while (money != 0 && i < a.size())
    {
        if (a[i] <= money)
        {
            //cout << a[i] << endl;
            money -= (long long)a[i];
            count++;
        }
        else
        {
            i--;
        }
    }
    cout << count;
}