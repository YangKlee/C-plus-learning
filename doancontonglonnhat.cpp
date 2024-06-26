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
void doancon_sumMax(vector <int> a, int l, int r, int max, pair <int, int> posSumMax)
{
    
    if(l >= r)
    {
        cout << "Doan con tong nho nhat: ";
        for(int i = posSumMax.first; i <= posSumMax.second; i++)
        {
            cout << a[i] << ' ';
        }
    }
    else
    {
        int s1 = sum_arr(a,l+1,r);
        int s2 = sum_arr(a, l, r-1);
        //cout << s1 << ' ' << s2 << endl;
        if(s1 <= s2)
        {
            if(s1 < max)
                doancon_sumMax(a,l+1,r,s1,make_pair(l+1,r));
            else
                doancon_sumMax(a,l+1,r,max,posSumMax);
        }
        else
        {
            if(s2 < max)
                doancon_sumMax(a,l,r-1,s2,make_pair(l,r-1));
            else
                doancon_sumMax(a,l,r-1,max,posSumMax);
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
    doancon_sumMax(a, 0, n-1, sum_arr(a,0,n-1) ,make_pair(0,n-1));
}
/*8
-1 5 -3 6 9 4 -7 2*/