#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <long long> a(n);
    long long tmp = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        //long long x; cin >> x;
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i-1] > a[i])
        {
            count += abs(a[i-1] - a[i]);
            a[i] = a[i-1] +1;
        }
        else if
    }
    cout << count;

}