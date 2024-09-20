#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    cin >> c;
    if( c >= 'A' && c <= 'Z')
        c += 32;
    else if(c >= 'a' && c <= 'z')
        c -= 32;
    else
        c = c;
    cout << c ;
}