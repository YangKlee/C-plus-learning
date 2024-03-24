#include <bits/stdc++.h>
using namespace std;

void input_arr(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

    }
    
}
void outarr(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout <<'\n';
    
}
long long move(long long a[], int n)
{
    long long taget = 0;

    for (int i = 0; i < n-1; i++)
    {
        if(a[i+1] < a[i] )
        {
            taget += (a[i]) - a[i+1] ;
            //cout << "taget = "<< taget << endl;
            a[i+1] = a[i];
        }
    }
    //outarr(a,n);
    return taget;

}
int main()
{

    int n;
    cin >> n;
    long long *a = new long long[n];
    input_arr(a,n);
    cout << (long long)move(a,n);

}