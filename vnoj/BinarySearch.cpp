#include <bits\stdc++.h>
using namespace std;
int BinarySearch(int a[], int x, int l, int r)
{
    if(l>r)
        return -1;
    else
    {
        int privot = (l+r)/2;
        if(a[privot] == x)
        {
            return privot;
        }
        else if(a[privot] < x)
        {
            return BinarySearch(a,x,privot+1,r);
        }
        else if(a[privot] > x)
        {
            return BinarySearch(a,x,l,privot-1);
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