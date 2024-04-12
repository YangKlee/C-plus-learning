#include<bits/stdc++.h>
using namespace std;
int GetLocationX(vector <int> a, int x,int k)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] == x)
        {
            count++;
        }
        if(count == k)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n, x, k;
    cin >>  n >> x >> k;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << GetLocationX(a,x,k);
      
}