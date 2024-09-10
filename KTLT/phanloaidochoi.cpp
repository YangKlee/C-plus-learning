#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float t;
    cin >> t;
    if(t > 9.0)
        cout << "VERRY GOOD";
    else if(t > 5.0)
        cout << "GOOD";
    else
        cout << "SAFE";
}