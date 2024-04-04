#include <bits/stdc++.h>
using namespace std;

int create_bits(bool a[], int n, int k, int x)
{
    if(n == 0)
        return 0;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if(k/2 <= i)
            {
                a[i-1] = 0;
            }
            else
            {
                a[i-1] = 1;
            }
            return create_bits(a[], n, k/2,)
        }
        
    }
}


int main()
{
    int n;
    //cin >> n;
    int k = pow(2,n);
    for (int i = 1; i <= pow(2,n); i++)
    {

    }
    
}