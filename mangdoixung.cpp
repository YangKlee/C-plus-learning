#include <iostream>
#include <math.h>
using namespace std;
void input_Array(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
bool checkdoixung(int a[], int n, int k)
{
    if(k == 0)
    {
        return 1;
    }
    else
    {
        if(a[abs(k - 1)] != a[abs((k - 1) -(n - 1))])
        {
            return 0;
        }
        return checkdoixung(a,n, k - 1 );
    }
}
int main()
{
    int n, s;
    cout << "Nhap n: "; cin >> n;
    int a[n];
    cout << "Nhap lan luot cac phan tu trong mang: ";
    input_Array(a,n);
    if(checkdoixung(a,n,n))
        cout << "La so doi xung";
    else
        cout << "Khong phai la so dxung"

}