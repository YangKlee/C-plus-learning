#include "iostream"
#include "math.h"
using namespace std;
void input_Array(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
void detect_sum_0(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            if(sum == 0)
            {
                cout << "Vi tri la: " << i << " den "<< j;
            }

        }

    }
}
int main()
{
    int n;
    cout << "Nhap n: "; cin >> n;
    int a[n];
    cout << "Nhap lan luot cac phan tu trong mang: ";
    input_Array(a,n);
    detect_sum_0(a,n);
}