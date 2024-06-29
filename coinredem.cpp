#include<bits/stdc++.h>
using namespace std;
void doitien(vector <int> &redem, vector <int> money , int x)
{
    for(int i = 0; i < money.size(); i++)
    {
        if(money[i] <= x)
        {
            redem[i] = x/money[i];
            x = x%money[i];
        }
    }
}
int main()
{
    int n, x;
    cout << "Nhap so to tien: ";
    cin >> n;
    vector <int> money(n);
    cout << "Nhap so tien: ";
    for(int i = 0; i < n; i++)
    {
        cin >> money[i];
    }
    cout << "Nhap so tien: ";
    cin >> x;
    sort(money.begin(), money.end(), greater());
    vector <int> redem(n,0);
    doitien(redem, money, x);
    for(int i = 0; i < n; i++)
    {
        cout << money[i] << ' ' << redem[i] << endl;
    }


}