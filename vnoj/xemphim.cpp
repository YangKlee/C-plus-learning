#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, n, sum = 0;
    cin >> w >> n;
    vector <int> weightCow(n);
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        weightCow[i] = tmp;
    }
    sort(weightCow.begin(), weightCow.end(), greater<>());
    for (int i = 0; i < n; i++)
    {
        
        if (sum + weightCow[i] <= w)
            sum += weightCow[i];
            
    }
    cout << sum;
}