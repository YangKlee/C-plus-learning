#include <iostream>
using namespace std;
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
bool checkTangDan(int a[], int n)
{
    if(n <= 1 )
        return 1;
    else
    {
        if(a[n - 1] < a[n-2])
            return 0;
        else
            return checkTangDan(a, n-1);
    }
}
int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    inputArray(a,n);
    if(checkTangDan(a, n))
        cout << "Day so tang!" << endl;
    else
        cout << "Day so hong tang!" << endl;

}