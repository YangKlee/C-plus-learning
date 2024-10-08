#include <bits/stdc++.h>
using namespace std;
float power(float a, int n)
{
    if (n == 1)
        return a;
    else
    {
        if (n % 2 == 0)
            return power(a , n/2) * power(a, n/2);
        else
            return power(a , n/2) * power(a, n/2) * a;
    }
}
int main()
{
    float a;
    int n;
    do
    {
        cout << "Nhap a, n: ";
        cin >> a >> n;
    } while (a <= 0);
    
    cout << "Luy thua la: "<< power(a,n);
}