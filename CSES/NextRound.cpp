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
    int n, k;
    cin >> n >> k;
    int count = 0;
    vti a;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
        if (i > k - 1)
        {
            if (a[k - 1] > a[i])
            {
                break;
            }
        }
        if (a[i]!= 0)
            count++;
    }
    cout << count;
}