#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int x;
    if(a > b)
        x = b;
    else
        x = a;
    int k = 1;
    for(int i = 2; i <= x; i++)
    {
        if(a % i == 0 && b%i == 0)
        {
            k = i;
        }
    }
    cout << a/k  << ' '<<b/k; 
}