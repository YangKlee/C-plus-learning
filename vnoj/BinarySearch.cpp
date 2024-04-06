#include <bits\stdc++.h>
using namespace std;
int BinarySearch(int a[], int x, int l, int r)
{
    if(l>r)
        return -1;
    else
    {
        int m = (l+r)/2;
        if(a[m] == x)
            return m;
        else
        {
            if(a[m] > x)
                return BinarySearch(a,x,l,m-1);
            else
                return BinarySearch(a,x,m+1,r);
        }
    }
}
int main()
{
    int n,x;
    cin >> n;
    
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    cout << BinarySearch(a,x,0,n-1);
    
}