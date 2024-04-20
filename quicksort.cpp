#include<bits/stdc++.h>
using namespace std;
int PhanHoach(vector <int> &a, int l, int r)
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
    return i;
}
void QuickSort(vector <int> &a, int l, int r)
{
    int q = PhanHoach(a,l,r);
    if(l < q-1) QuickSort(a,l,q-1);
    if(q < r) QuickSort(a,q,r);
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
    QuickSort(a,0,a.size()-1);
    for(int x:a)
    {
        cout << x << ' ';
    }
    
}