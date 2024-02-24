#include "iostream"
using namespace std;
void input_Array(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
bool check_B_con_A(int a[], int b[], int n, int m)
{
    int privot = 0, count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = privot; j < n; ++j) {
            if(a[j] == b[i])
            {
                privot = j;
                count++;
                break;
            }
        }
    }
    if(count == m)
        return true;
    else
        return false;
}
int main()
{
    int n, m; // n aka do dai mang a, n aka do dai mang b
    cout << "Nhap lan luot do dai mang a va b: " << endl;
    cin >> n >> m;
    int a[n], b[m];
    cout << "Nhap mang A: ";
    input_Array(a, n);
    cout << "Nhap mang B: ";
    input_Array(b, m);
    if(check_B_con_A(a,b, n,m))
    {
        cout << "B con A";
    }
    else
    {
        cout << "B khong phai con A";
    }
}
