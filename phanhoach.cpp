#include<bits/stdc++.h>
using namespace std;
int PhanHoach(vector <int> &a, int l, int r)
{
    // dat phan tu chot o giua
    int privot = a[(l+r)/2];
    cout << privot << endl;
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
    cout << PhanHoach(a,0,a.size()-1) << endl;
    for(int x:a)
    {
        cout << x << ' ';
    }
}