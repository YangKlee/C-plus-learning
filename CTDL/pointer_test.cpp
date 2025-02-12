#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 10;
    int* p = &x;
    int** q = &p;
    **q = 12;

    cout << "x = " << x << " &x = " << &x << endl;
    cout << "p = " << p << " *p = " << *p << endl;
}