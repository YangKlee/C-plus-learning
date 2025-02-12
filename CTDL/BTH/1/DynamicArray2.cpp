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
void displayArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *a << " ";
        a++;
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    int *a = inputDynamicArr(n);
    displayArr(a,n);
}