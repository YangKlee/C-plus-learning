#include<bits/stdc++.h>
using namespace std;
int gt(int a, int n)
{
    if(n == 1)
    {
        return a;
    }
    else
    {
        if(n%2 == 0) 
            return gt(a,n/2) * gt(a,n/2);
        else
            return gt(a,n/2) * gt(a,n/2)*a;
    }
}
int main()
{
    int a,n;
    cin >> a >> n;
    cout << gt(a,n);
}