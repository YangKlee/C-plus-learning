#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cm;
    cin >> cm;
    float solan = 1;
    if( cm <= 2)
        solan = 0;
    else
        solan = log2(cm)  - 1.0;
    cout << (long long)ceil(solan) << endl;
}