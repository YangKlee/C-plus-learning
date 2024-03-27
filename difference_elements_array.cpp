#include <bits/stdc++.h>
using namespace std;
void input_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
void out_arr(vector <int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' '  ;
    }
    cout << endl;
}
bool KTraTonTai(vector <int> a , int x)
{
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] == x)
        {
            return false;
        }
    }
    return true;
    
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    input_arr(a,n);
    vector <int> b;
    for (int i = 0; i < n; i++)
    {
        if(KTraTonTai(b,a[i]))
            b.push_back(a[i]);
    }
    out_arr(b);
}