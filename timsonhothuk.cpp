#include<bits/stdc++.h>
using namespace std;
void Merge(vector <int> &a, int l, int m, int r)
{
    vector <int> tmp1(a.begin()+l, a.begin()+m+1);
    vector <int> tmp2(a.begin()+m+1, a.begin() +r+1);
    int i  = 0, j = 0;
    while(i < tmp1.size() && j < tmp2.size())
    {
        if(tmp1[i] <= tmp2[j])
        {
            a[l] = tmp1[i]; l++; i++;
        }
        else
        {
            a[l] = tmp2[j]; l++; j++;
        }
    }
    while(i < tmp1.size())
    {
        a[l] = tmp1[i]; i++; l++;
    }
    while(j < tmp2.size())
    {
        a[l] = tmp2[j]; j++; l++;
    }
}
void MergeSort(vector <int> &a, int l, int r)
{
    if(l >= r) return;
    int m = (l+r)/2;
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    Merge(a,l,m,r);
}
int main()
{
    int n; cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    MergeSort(a,0,a.size()-1);
    int k; cin >> k;
    cout << "So lon thu k la: " << a[a.size()-1 - (k-1)];
    
}