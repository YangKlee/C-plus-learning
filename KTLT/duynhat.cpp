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
    int n;
    cin >> n;
    vtll a;
    ll tmp; 
    cin >> tmp;
    a.push_back(tmp);

    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        if (tmp != a[a.size()-1])
        {
            a.push_back(tmp);
        }
    }
    for (int i : a)
    {
        cout << i << " ";
    }

}