#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, count = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == x)
            count++;
    }
    if(count == 0)
        cout << -1;
    else
        cout << count;
    
}