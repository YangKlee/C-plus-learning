#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cm;
    cin >> cm;
    float solan = 0;
    if( cm <= 2)
        solan = 0;
    else
        solan = (log(cm)/ log(2)) -1.0;
    printf("%.0f", solan);
}