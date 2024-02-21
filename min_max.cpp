#include "iostream"
using namespace std;
void input_array(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << "A[" << i << "]= ";
        cin >> a[i];
    }
}
int max(int a[], int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}
int min(int a[], int n)
{
    int privot = a[0];
    for (int i = 0; i < n; ++i) {
        if(a[i] < privot)
            privot = a[i];
    }
    return privot;
}
int main()
{
    int n;
    cout << "Nhap n: " ;
    cin >> n ;
    int a[n];
    input_array(a,n);
    cout << "Max is: " << max(a,n) << endl;
    cout << "Min is: " << min(a,n) << endl;

}