#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, a, b, c ,d;
    cin >> x >> a >> b >> c >> d;
    long long price = 0;
    if(x >= 0 && x <= 50)
    {
        price += x * a; 
    }
    if (x >= 51 && x <= 100)
    {
        price += 50 * a; 
        x -= 50;
        price += x *b;
    }
    if (x >= 101 && x <= 150)
    {
        price += 50 * a; 
        x -= 50;
        price += 100 * b; 
        x -= 100;
        price += x *c;
    }
    if (x >= 151)
    {
        price += 50 * a; 
        x -= 50;
        price += 100 * b; 
        x -= 100;
        price += 150 * c; 
        x -= 150;
        price += x *d;
    }
    cout << price;
}