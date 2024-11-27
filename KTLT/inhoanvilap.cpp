#include <bits/stdc++.h>
using namespace std;
vector <int> x; // chua so nhap vao
vector <int> hv; // chua hoan vi cac anh xa vi tri cua x 
int n;
void show()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[hv[i]] << " ";
    }
    cout << "\n";
}
int Next()
{
    hv[n] +=  1;
    while (1)
    {
        bool isClean = 1;
        for (int i = 2; i <= n; i++)
        {
            if (hv[i] > n)
            {
                hv[i-1] += hv[i] - n;
                hv[i] = 1;
                isClean = 0;
            }
        }
        if (isClean)
            break;
    }
    if (hv[1] > n)
    {
        return 0;
    }
    return 1;
}
void thLap()
{
    show();
    while (1)
    {
        if(Next())
        {
            show();
        }
        else
            break;
        
    }
    
}
int main()
{
    cin >> n;
    x.resize(n+1);
    hv.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        hv[i] = 1;
    }
    thLap();
}