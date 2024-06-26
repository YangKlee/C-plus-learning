#include<bits/stdc++.h>
using namespace std;

int TongDoanCon(vector<int> a, int l, int m, int r)
{
    int suml = 0;
    for(int i = l; i <= m ; i++)
    {
        suml += a[i];
    }

    int sumr = 0;
    for(int i = m; i <= r ; i++)
    {
        sumr += a[i];
    }
    return suml+sumr;
}
void MaxSumSubArray(vector <int>a, int l, int r, int maxSum, pair<int,int>MaxPos)
{
    if(l >= r)
        //
    else
    {
        int m = (l+r)/2;
        
    }
}
int main()
{
    int n;
    vector <int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}