#include <bits/stdc++.h>
using namespace std;

void input_arr(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
void out_arr(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}
bool check_tangdan(long long a[], int n)
{
    if(n == 0)
        return 1;
    else
    {
        if(a[n-2] > a[n-1])
            return 0;
        else
            return check_tangdan(a,n-1);
    }
}
int move(long long a[], int n)
{
    int min = 0;
    while(check_tangdan(a,n) == false)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(a[i] >= a[i+1])
            {
                a[i+1] += 1;

            }
            min ++;
        }
        //out_arr(a,n);
        //cout << '\n';
    }
    return min;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long *a = new long long[n];
    input_arr(a, n);
    cout << move(a,n);

}