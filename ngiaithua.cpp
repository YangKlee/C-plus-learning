#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> gt(n+1);
    gt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        gt[i] = gt[i-1] * i;
    }
    cout << gt[n];
    
}