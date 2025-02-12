#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *p = new int;
    *p = 10;
    // Print the value of p and the value pointed to by p
    cout << "p = " << p << ", *p = " << *p << endl;
    delete p;
    cout << "p = " << p << ", *p = " << *p << endl;
    p = nullptr;
    cout << "p = " << p << ", *p = " << *p << endl;

}