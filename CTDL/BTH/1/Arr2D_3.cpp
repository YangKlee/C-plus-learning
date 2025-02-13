#include <iostream>
using namespace std;
const int MAXCOLS = 100;
//Nhập một mảng 2 chiều với số dòng m, số cột n.
void inputArr2D(int arr[][MAXCOLS], int m, int n)
{
    for (int i = 0; i < m ; i++)
    {
     
        for (int j = 0; j < n; j++)
        {
            printf("arr[%d][%d] = ", i+1, j+1);
            cin >> arr[i][j];
        }
    }
}
//In một mảng 2 chiều với số dòng m, số cột n.
void printArr2D(int arr[][MAXCOLS], int m, int n)
{
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
//Cộng hai mảng hai chiều a, b có m dòng, n cột lưu vào mảng c.
void addArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int n, int c[][MAXCOLS])
{
    if (m != n)
    {
        cout << "Khong the cong ma tran!" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c[i][j] = 0; // khoi tao truoc gia tri
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }
}
int main()
{
    // m la so hang, n la so cot
    int m, n; 
    cout << "Nhap lan luot so hang va so cot cua mang 2 chieu A: "; cin >> m >> n;
    int arr[100][100];
    inputArr2D(arr, m , n);
    printArr2D(arr, m, n);
    int c[100][100];
    

}