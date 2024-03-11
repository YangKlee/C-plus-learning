#include <iostream>
using namespace std;
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
bool checkTangDan(int a[], int n,int i)
{
    if(i >= n-1)
        return 0;
    else
    {
        if(a[i] > a[i+1])
            return 0;
        else
            return checkTangDan(a, n, i+=1);
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
    if(checkTangDan(a, n, 0))
        cout << "Day so tang!" << endl;
    else
        cout << "Day so k tang!" << endl;

}