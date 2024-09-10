#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a == 0)
    {
        if(b == 0)
        {
            cout << "INFINITE";
            exit(0);
        }
        else
        {
            cout << "NO SOLUTION";
            exit(0);
        }

    }
    int result = -b/a;
    cout << result;
}