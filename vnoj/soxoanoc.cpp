#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x,y;
        cin >> y >> x;
        if(y >= x) // nam duoi duong cheo chinh
        {
            if(y%2 == 0)
            {
                cout << y*y - (x-1) << endl;
            }
            else
            {
                cout << ((y-1)*(y-1)+1) + (x-1) << endl;
            }

        }
        else
        {
            if(x%2 == 0)
            {
                cout << ((x-1)*(x-1)+1) + (y-1) << endl;
            }
            else
            {
                cout << x*x - (y-1) << endl;
            }
        }

    }
    
}