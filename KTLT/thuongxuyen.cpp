#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
int demSL(vtll a, int x)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    vtll a(n);
    set <ll> num;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num.insert(a[i]);
    }
    int count = 0;
    int maxLoopNum = -10e3;
    int maxLoop = 0;
    for (int x : num)
    {
        int countX = demSL(a,x);
        if (countX > 2)
            count++;
        if (countX >= maxLoop)
        {
            if (x > maxLoopNum)
                maxLoopNum = x;
            maxLoop = countX;
        }
    }
    cout << count << "\n" << maxLoopNum << endl;
}