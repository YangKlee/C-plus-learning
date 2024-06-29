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
        prefix[i] = max(a[i], prefix[i-1]+a[i]);
    }
    int max_sum = 0;
    int max_sum_index = 0;

    for(int i = 0; i < n; i++)
    {
        if(prefix[i] > max_sum)
        {
            max_sum_index = i;
            max_sum = prefix[i];
        }
    }
    cout << "Tong lon nhat la: " << max_sum << endl;
    // truy vet
    while(max_sum > 0)
    {
        cout << a[max_sum_index] << ' ';
        max_sum -= a[max_sum_index];
        max_sum_index --;
    }
    
}