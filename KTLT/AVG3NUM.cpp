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
    ll a, b, c, x;
    cin >> a >> b >> x;
    for (int i = 1 ; i <= 100; i++)
    {
        if ((a+b+i)/3 == x)
        {
            cout <<  i << endl;
            break;
        }
    }

}