#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, k;
    cin >> n >>k;
    if (n >=k)
        cout <<  n + (n/k) + (n%k);
    else
        cout << n;
    
}