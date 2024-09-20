#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long h = 0, m = 0, s = 0,d;
    cin >> d;
    h = d / 3600ll;
    m =  (d%3600ll) / 60ll;
    s = ((d%3600ll)% 60ll);
    cout  << h << ' ' << m << ' ' << s;

}