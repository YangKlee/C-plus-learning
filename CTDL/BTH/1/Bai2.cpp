#include <iostream>
#include <set>
#include <string>
using namespace std;

// hàm tính trung bình cộng các số trong mảng
float avgArr(int a[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= a[i];
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
        cout << a[i] <<  " ";
    }
    cout << "\n";
}

int main()
{
    int n, m, x;
    cout << "Nhap so phan tu mang a: ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Nhap so phan tu mang b: ";
    cin >> m;
    int* b = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << "Trung binh cong mang a: " << avgArr(a, n) << endl;
    cout << "Trung binh cong mang b: " << avgArr(b, m) << endl;
    cout << "Nhap so nguyen X: " ; cin >> x;
    if (findArr(a, n, x))
    {
        cout << "So nguyen x ton tai trong mang a" << endl;
    }
    else
    {
        cout << "So nguyen x khong ton tai trong mang a" << endl;
    }
    sortArr(a, n);
    cout << "Mang A da sap xep: " ; displayArr(a, n);
    sortArr(b, m);
    cout << "Mang A da sap xep: " ; displayArr(b, m);
    int c[1000];
    int l = mergeArr(a, n, b, m, c);
    cout << "Mang gop cua mang A va B la: " ; displayArr(c, l) ;
    
    int num[1000];
    int sl[1000];
    cout << "So lan xuat hien cua tung phan tu trong mang A la: ";
    int d_size = countArr(a, n, num, sl);
    cout << "So" << "\t" << "So lan" << endl;
    for (int i = 0; i < d_size; i++)
    {
        cout << num[i] << "\t" << sl[i] << endl;
    }
}