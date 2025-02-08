#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
bool isSoNon(vti a, int maxI)
{

    bool dk1 = false;
    bool dk2 = false;
    if (a.size() == 1)
        return false;
    else if (maxI == 0)
        return false;
    else if (maxI == a.size()-1)
        return false;
    for (int i = 0; i < maxI; i++)
    {
        if (a[i] >= a[maxI])
        {
            cout << i << endl;
            return false;
        }
    }

    for (int i = maxI+1; i < a.size(); i++)
    {
        if (a[i] >= a[maxI])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    vti a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = -10e3, maxindex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxindex = i;
        }
    }
    if (isSoNon(a,maxindex))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
}