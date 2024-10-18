#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    if (k > n || k == 0)
        cout << n ;
    else
    {
        int somidoi = n/k;
        cout << n + somidoi ;
    }
}