#include <bits/stdc++.h>
using namespace std;
void array_out(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout <<a[i];
    }
    cout << '\n';
    
}
int sum = 0;
void gray(int n, int k, int a[])
{
    for(int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if(k == n-1)
            sum++;
        else
            gray(n,k+1,a);
    }

}
int main()
{
    int n;
    int *a = new int[n];
    cin >> n;
    gray(n,0, a);
    cout << sum;
}