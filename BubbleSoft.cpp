#include <bits\stdc++.h>
using namespace std;
void input_arr(int a[], int n)
{
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

}
void output_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void BubbleSoft(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i ; j++)
        {
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
        }
    }
    
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    input_arr(a,n);
    BubbleSoft(a,n);
    cout << '\n';
    output_arr(a,n);

}