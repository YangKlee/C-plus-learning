#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x, stack = 0;
    cin >> n;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == x)
        {
            cout << i << ' ';
            stack = 1;
        }
    }
    if(stack = 0)
        cout << -1 << ' ';

    
}