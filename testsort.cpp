#include<bits/stdc++.h>
using namespace std;
// sap xep so luong chu so tang dang
int DemChuSo(int n)
{
    if(n <= 9) return 1;
    else return 1+DemChuSo(n/10);
}
bool dk(int a, int b)
{
    return DemChuSo(a) < DemChuSo(b);
}
int main()
{
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end() , dk);
    for(int x:a)
    {
        cout << x << ' ';
    }
}