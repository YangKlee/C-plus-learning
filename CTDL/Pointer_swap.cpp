#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;

}
int main()
{
    int x = 5, y = 8;
    swap(x, y);
    cout << x << " " << y;
}