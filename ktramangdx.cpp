#include<bits/stdc++.h>
using namespace std;
void input_arr(int a[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cin >> a[i];
    }
    
}
bool KTDoiXung(int a[], int n)
{
    for (int i = 0; i < n/2; i++)
    {
        if(a[i] != a[n-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    input_arr(a,n);
    if(KTDoiXung(a,n)) cout << "Mang doi xung" << endl;
    else cout << "Mang khong doi xung" << endl;
}