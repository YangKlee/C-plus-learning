#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
int main()
{
    IOS;
    int a, b, c;
    while ( cin >> a >> b >> c)
    {
        if (a + b == c || a + c == b || b + c == a)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
    }
}