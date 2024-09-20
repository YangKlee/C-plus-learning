#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a,b;
    cin >> a >>b;
    // chuyen tat ca ve chu in hoa
    if( a >= 'a' && a <= 'z')
        a -= (char)32;
    if(b >= 'a' && b <= 'z')
        b -= (char)32;
    //cout << a << b;
    int diff = (int)(a-b);
    cout << abs(diff) +1;

}