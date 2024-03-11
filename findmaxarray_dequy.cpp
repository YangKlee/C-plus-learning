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
        if(a[n-1] > max)
        {
            max = a[n-1];
        }
        return MaxArray(a, n - 1, max);
    }
    
}
int ln(int a[], int n)
{
    if(n == 1)
        return a[0];
    if(a[n - 1] > ln(a, n - 1))
        return a[n - 1];
    else
        return ln(a, n-1);

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
    cout << "Max = " << ln(a,n)<< endl;


}