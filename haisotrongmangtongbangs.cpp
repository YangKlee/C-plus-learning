#include "iostream"
#include "math.h"
using namespace std;
void input_Array(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
void sum_is_s(int a[], int n, int s)
{
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(a[i] + a[j] == s)
            {
                cout << "Hai so trong mang co tong bang S la: "<< a[i] <<" va " << a[j] << endl;
            }
        }
    }
}
int main()
{
    int n, s;
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap s: "; cin >> s;
    int *a = new int[n];
    cout << "Nhap lan luot cac phan tu trong mang: ";
    input_Array(a,n);
    sum_is_s(a,n,s);

}