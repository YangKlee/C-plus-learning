#include <iostream>
using namespace std;
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
int MaxArray(int a[], int n, int max)
{
    if(n == 0)
        return max;
    else    
    {
        if(a[n] > max)
        {
            max = a[n];
        }
        return MaxArray(a, n - 1, max);
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
    cout << "Max = " << MaxArray(a,n, a[0])<< endl;


}