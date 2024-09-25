#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, x;
    bool isVisible = false;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        long long tmp; cin >> tmp;
        if (x == tmp )
        {
            cout << i << " ";
            isVisible = true;
        }
    }
    if( isVisible == false)
        cout << -1;

}