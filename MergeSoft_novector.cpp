#include<bits/stdc++.h>
using namespace std;
void debug(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
void Merge(int a[], int l, int m, int r)
{
    int i = 0, j = 0, tmp1_size = m - l+1, tmp2_size =  r - m;

    int *tmp1 = new int[tmp1_size];
    int *tmp2 = new int[tmp2_size];
    for(int x = 0 ; x < tmp1_size; x++)  
        tmp1[x] = a[l+x];
    for(int x = 0 ; x < tmp2_size; x++)
        tmp2[x] = a[m+1+x];
    while(i < tmp1_size && j < tmp2_size)
    {
        if(tmp1[i] <= tmp2[j])
        {
            a[l] = tmp1[i]; i++; l++;
        }
        else
        {
            a[l] = tmp2[j]; j++; l++;
        }
    }
    while(i < tmp1_size)
    {
        a[l] = tmp1[i]; l++; i++;
    }
    while(j < tmp2_size)
    {
        a[l] = tmp2[j]; l++; j++;
    }
}

void MergeSoft(int a[], int l, int r)
{   //cout <<"merge "<< l << ' ' << r << endl;
    if(l < r)
    {
        int m = (l+r)/2;
        MergeSoft(a,l,m);
        MergeSoft(a,m+1,r);
        Merge(a,l,m,r);
    }
}
// Code by @YangKlee
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    MergeSoft(a,0,n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}