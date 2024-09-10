#include <bits/stdc++.h>
using namespace std;
struct NgaySinh{
    int d;
    int m;
    int y;

}SinhVien1, SinhVien2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> SinhVien1.d >> SinhVien1.m >> SinhVien1.y;
    cin >> SinhVien2.d >> SinhVien2.m >> SinhVien2.y;
    if(SinhVien1.y != SinhVien2.y)
    {
        if(SinhVien1.y < SinhVien2.y)
            cout << 1;
        else 
            cout << 2;
    }
    else
    {
        if(SinhVien1.m != SinhVien2.m)
        {
            if(SinhVien1.m < SinhVien2.m)
                cout << 1;
            else
                cout << 2;
        }
        else
        {
            if(SinhVien1.d != SinhVien2.d)
            {
                if(SinhVien1.d < SinhVien2.d)
                    cout << 1;
                else
                    cout << 2;
            }
            else
            {
                cout << 0;
            }
        }
    }

}