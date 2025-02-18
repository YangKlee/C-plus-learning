#include <iostream>
using namespace std;
const int MAXCOLS = 100;
struct Matrix
{
    int m; // dong
    int n; // cot
    int arr[100][100];
};

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
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0; // khoi tao truoc gia tri
                c[i][j] = a[i][j] + b[i][j];
            }
        }
}
// Tìm vị trí số lớn nhất trong mảng hai chiều.
int maxArr2D(int arr[][MAXCOLS], int m, int n, int &rowMax, int &colMax)
{
    int max = -INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                rowMax = i;
                colMax = j;
            }
        }
    }
    return max;
}
// Nhân hai ma trận (mảng 2 chiều) a có m dòng p cột và b có p dòng n cột lưu vào ma trận c có m dòng, n cột.
void multiplyArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int p, int n, int c[][MAXCOLS])
{
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < p ; k++)
            {
                sum += (a[i][k] * b[k][j]);
            }
            c[i][j] = sum;
        }
    }
}
int main()
{
    Matrix a, b, c;
    cout << "Nhap so hang va so cot ma tran A: "; cin >> a.m >> a.n;
    cout << "Nhap ma tran A: " << endl;
    inputArr2D(a.arr, a.m, a.n);
    cout << "Nhap so hang va so cot ma tran B: "; cin >> b.m >> b.n;
    cout << "Nhap ma tran B: " << endl;
    inputArr2D(b.arr, b.m, b.n);
    cout << "Ket qua A + B: " << endl;
    if (a.m != b.m || a.n != b.n)
    {
        cout << "Khong the cong ma tran!" << endl;

    }
    else
    {
        //c.m = a.m; c.n = a.n;
        addArr2D(a.arr, b.arr, a.m, a.n, c.arr);
        printArr2D(c.arr, a.m, a.n);
    }
    int rowMax = -1, colMax = -1;
    int max = maxArr2D(a.arr, a.m, a.n, rowMax, colMax);
    printf("So lon nhat cua ma tran A la %d va nam o dong %d cot %d ", max, rowMax +1, colMax +1 );
    max = maxArr2D(b.arr, b.m, b.n, rowMax, colMax);
    printf("So lon nhat cua ma tran B la %d va nam o dong %d cot %d ", max, rowMax +1, colMax +1 );
    cout << "Ket qua A * B: " << endl;
    if (a.n != b.m)
    {
        cout << "Khong the nhan " << endl;
    }
    else
    {
        multiplyArr2D(a.arr, b.arr, a.m, a.n, b.n, c.arr);
        printArr2D(c.arr, a.m, b.n);
    }
}