#include <bits/stdc++.h>
using namespace std;
int n, k;
vector <int> x; // tap chua cac phan tu
vector <int> c; // tap chua to hop chap k (anh xa voi vi tri tu 1 den n cua mang x)
void inilazie()
{
    x.resize(n+1);
    c.resize(k+1);
    for (int i = 1; i <= k; i++)
    {
        c[i] = i;
    }
}
void show()
{
    for (int i = 1; i <= k; i++)
    {
        cout << x[c[i]] << " ";
    }
    cout << "\n";
}
int fNext()
{
    int pos = -1;
    for (int i = k; i >= 1; i--)
    {
        if (c[i] != n- k+i )
        {
            pos = i;
            break;
        }
    }
    return pos;
}
void next()
{
    while(1)
    {
        int pos = fNext();
        if (pos == -1)
        {
            break;
        }
        else
        {
            c[pos] ++;
            for (int i = pos+1; i <= k; i++)
            {
                c[i] = c[i-1] +1;
            }
            show();
        }
    }
}
int main()
{
    cin >> n >> k;
    inilazie();
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    show();
    next();
}