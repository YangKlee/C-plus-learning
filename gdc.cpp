#include<bits/stdc++.h>
using namespace std;
int gdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gdc(b, a%b);
}
int get(int n)
{
    float tu = pow((1+ sqrt(5)), n) - pow((1- sqrt(5)),n);
    return tu/(pow(2,n)*sqrt(5));
}
int main()
{
    int a, b, m;
    cin >> a >> b  >> m;
    int fiba = get(a);
    int fibb = get(b);
    //cout << fiba << ' '<< fibb;
    cout << gdc(fiba, fibb)%m;
}