#include <bits/stdc++.h>
using namespace std;
void HaNoiTower(int n, int a, int b, int c)
{
    if(n>0)
    {
        HaNoiTower(n-1,a,c,b);
        cout << a <<' '<< b << endl;
        HaNoiTower(n-1,c,b,a);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << pow(2,n) - 1 << endl;
    HaNoiTower(n,1,3,2);

}