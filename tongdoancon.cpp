#include<bits/stdc++.h>
using namespace std;
int sum(vector <int> a, int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += a[i];
    }
    return sum;
}
void max_SubArray(vector <int> a, int l, int r, int min_index)
{
    if(a[min_index] >= 0)
    {
        for(int i = l; i <= r; i++)
        {
            cout << a[i] << ' ';
        }
    }
    int min = INFINITY;
    for(int i = l; i <= r;i++)
    {
        if(a[i] < min)
        {
            min = a[i];
            min_index = i;
        }   
    }
    if(sum(a,l,min_index) > sum(a,min_index+1,r))
    {
        return max_SubArray(a,l,min_index, min_index);
    }
    else
    {
        max_SubArray(a,min_index+1,r,min_index);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {       
        cin >> a[n];
    }
    max_SubArray(a,0, n-1, -1);
    
}