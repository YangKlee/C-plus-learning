#include <iostream>
using namespace std;
// Hàm nhập mảng động n số nguyên. Trả về con trỏ đến phần tử đầu tiên của mảng.
int* inputDynamicArr(int n)
{
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    return a;
}
//Hàm in mảng động n số nguyên có địa chỉ từ arr.
void printDynamicArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
// Hàm thêm một số x vào cuối mảng arr có n số.
void appendDynamicArr(int *arr, int &n, int x)
{
    int* startArr = arr;
    int *new_arr = new int[n+1];
    int *start_newArr = new_arr;
    for (int i = 0; i < n; i++)
    {
        *new_arr = *arr;
        new_arr++; arr++; 
    }
    new_arr = start_newArr;
    *(new_arr + n) = x;
    n += 1;
    arr = new int[n];
    arr = startArr;   
    for (int i = 0; i < n; i++)
    {
        *arr = *new_arr;
        arr++; new_arr++;
    }
    arr = startArr;
}
int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int *a = inputDynamicArr(n);
    cout << "Nhap phan tu de them vao mang: ";
    int x;
    cin >> x;
    appendDynamicArr(a, n, x);
    cout << "Ket qua: ";
    printDynamicArr(a, n);
}