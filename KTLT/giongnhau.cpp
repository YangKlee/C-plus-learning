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
    vti a(n);
    vti b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];        
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    
}