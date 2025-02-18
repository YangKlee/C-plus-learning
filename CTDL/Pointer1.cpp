#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *p = new int;
    cout << "p = " << p <<  endl;
    delete p;
    cout << "p = " << p <<  endl;
    p = new int;
    cout << "p = " << p <<  endl;

}