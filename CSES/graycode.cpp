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
    cin >> n;
    for (int i = 1; i <= pow(n,2); i++)
    {
        for(int j = 1; j <= n; j++)
        {
            
        }
    }
    
}