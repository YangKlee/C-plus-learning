#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
int dpa[100000];
int dpb[100000];
int dpc[100000];

int main()
{

    int n;
    cin >> n;
    int lastMax = 0;
    int lastIndex = 0;
    dpa[0] = dpb[0] = dpc[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b>> c;
        dpa[i] = max(dpb[i-1] + a, dpc[i-1] + a);
        dpb[i] = max(dpa[i-1] + b, dpc[i-1] + b);
        dpc[i] = max(dpb[i-1] + c, dpa[i-1] + c);
    }
    cout << max(dpa[n], max(dpb[n], dpc[n]));

}