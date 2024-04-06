#include <bits/stdc++.h>
using namespace std;
int lamtoan(int n, int x, int y, int a, int b)
{
    if(x <= 0 && y <= 0)
        return n;
    else
        return lamtoan(n-1, x-a, y -b, a,b );
}
int main()
{
    int n,x,y,a,b;
    cin >> n >> x >> y>> a>>b;
    cout << lamtoan(n, x,y,a,b);
    
}