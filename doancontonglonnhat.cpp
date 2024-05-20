#include<bits/stdc++.h>
using namespace std;

int sum_arr(vector <int> a, int l, int r)
{
    int sum = 0;
    for(int i = l; i <= r; i++)
    {
        sum += a[i];
    }
    return sum;
}

void doancon_sumMax(vector <int> a, int l, int r, int max)
{
    if(sum_arr(a,l,r) < max)
        cout << l << ' ' << r;
    else
    {
        int s1 = sum_arr(a,l+1,r);
        int s2 = sum_arr(a, l, r-1);
        if( s1 >= s2)
        {
             doancon_sumMax(a,l+1,r,s1);
        }
        else
        {
             doancon_sumMax(a,l,r-1, s2);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    doancon_sumMax(a, 0, n-1, sum_arr(a,0,n-1));
}