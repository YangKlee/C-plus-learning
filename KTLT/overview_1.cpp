#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) // chay den n+1 vi can hien thi ki tu * o cuoi
    {
        cout << '-';
        if(i == n) // in phan tu * khi du n phan tu -;
        {
            cout << "*";
        }
    }
    cout << "\n";
    
}