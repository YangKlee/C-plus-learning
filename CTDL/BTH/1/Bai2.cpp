#include <iostream>
#include <set>
using namespace std;

// hàm tính trung bình cộng các số trong mảng
float avgArr(int a[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= i;
    }
    return sum / n;
}
// hàm tìm một số nguyên  có trong mảng hay không
bool findArr(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return true;
    }
    return false;
}
// sắp xếp mảng theo thứ tự tăng 
void sortArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}
// gộp 2 mảng tăng dần
int mergeArr(int a[], int n, int b[], int m, int c[])
{
    //c = new int[n+m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            i++; k++;
        }
        else
        {
            c[k] = b[j];
            j++; k++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++; k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++; k++;
    }
    return n + m; // trả về kích thước mảng c

}
// Đếm số lần xuất hiện từng số trong mảng.
int countArr(int a[], int n, int b[], int d[])
{
    set <int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.insert(a[i]);
    }
    // copy tu set qua mang b
    int tmp_i = 0;
    for (int x : tmp)
    {
        b[tmp_i] = x;
        tmp_i++;
    }
    //c = new int[tmp_i +1];
    for (int i = 0; i <= tmp_i; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[i])
            {
                count++;
            }
        }
        d[i] = count;
    }
    return tmp_i+1;
}
// in mang
void displayArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n, m;
    cout << "Nhap so phan tu mang a: ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {

    }
}