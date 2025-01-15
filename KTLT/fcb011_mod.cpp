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
    ll n;
    cin >> n;
    stack <ll> res;
    n = abs(n);
    for (int i = 0; i < 3; i++)
    {
        res.push(n%10);
        n /= 10;
    }
    while(!res.empty())
    {
        cout << res.top();
        res.pop();
    }
}