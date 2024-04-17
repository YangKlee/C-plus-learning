#include <bits/stdc++.h>
using namespace std;
vector <long long> sumarray(vector <long long> values )
{
    vector <long long> sumarr;
    long long sum = 0LL;
    for(long long x: values)
    {
        sum += x;
        sumarr.push_back(sum);
    }
    return sumarr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector <long long> values;
    vector <long long> sum;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        values.push_back(x);
    }
    sum = sumarray(values);
    for(int i = 0; i < m; i++)
    {
        int l,r;
        cin >> l >> r;
        if(l == 0) cout << sum[r] << endl;
        else
        {
            cout << sum[r] - sum[l-1] << endl;
        }
    }
}
