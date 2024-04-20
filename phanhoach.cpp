#include<bits/stdc++.h>
using namespace std;
void PhanHoach(vector <int> &a, int l, int r)
{
    int privot = a[(l+r)/2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] < privot)
            i++;
        while(a[j] > privot)
            j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
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
        int x; cin >> x;
        a.push_back(x);
    }
    PhanHoach(a,0,a.size()-1);
    for(int x:a)
    {
        cout << x << ' ';
    }
}