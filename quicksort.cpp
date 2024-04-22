#include<bits/stdc++.h>
using namespace std;
int PhanHoach(vector <int> &a, int l, int r)
{
    // dat phan tu chot o giua
    int privot = a[(l+r)/2];
    int i = l, j = r;
    while(i <= j)
    {
        // i danh dau nhung phan tu > privot
        while(a[i] < privot) 
            i++;
        // j danh dau nhung phan tu < privot
        while(a[j] > privot) 
            j--;
        // dieu kien doi cho khi i <= j
        if(i <= j)
        {   
            // doi cho hai phan tu khong thoa man
            swap(a[i], a[j]); 
            i++;
            j--;
        }
    }
    // tra ve vi tri cua privot
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