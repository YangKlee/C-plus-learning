#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    x -= 2;
    // 5 , 6 la ngay cuoi tuan
    int sotuan = y/6;
    y = y%6;
    int tmp = 0;
    while (y > 0)
    {
        if (x != 5 && x != 6)
            tmp++;
        x++;
        y--;
    }
    cout << (sotuan * 6)-(2 * sotuan) + tmp;
    
}