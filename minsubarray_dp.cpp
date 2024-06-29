#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> prefix(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    prefix[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefix[i] = min(a[i], prefix[i-1]+a[i]);
    }
    int min_sum = INFINITY;
    int min_sum_index = 0;

    for(int i = 0; i < n; i++)
    {
        if(prefix[i] < min_sum)
        {
            min_sum_index = i;
            min_sum = prefix[i];
        }
    }
    cout << "Tong nho nhat la: " << min_sum << endl;
    /* DEBUG
    
    for(int x:prefix)
        cout << x << ' ';
    cout << endl;
    // truy vet
    */
    while(min_sum != 0)
    {
        cout << a[min_sum_index] << ' ';
        min_sum -= a[min_sum_index];
        min_sum_index --;
    }
    
    
}