#include <iostream>
using namespace std;
void input_Array(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
bool checkdoixung(int a[], int n)
{
    if(n > n/2)
        return 0;
    else
    {
        if(a[(n-1)-(n-1)] == a[n-1])
            return 1;
        return checkdoixung(a,n-1)
    }
}
int main()
{
    int n, s;
    cout << "Nhap n: "; cin >> n;
    int a[n];
    cout << "Nhap lan luot cac phan tu trong mang: ";
    input_Array(a,n);
}