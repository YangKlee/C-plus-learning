#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    int count = 0;
    for (int i = 1; i <= y ; i++)
    {
        //cout << i << endl;
        if(x > 8)
        {
            x = 2; i--;
            continue;
        }
        else
        {
            if(x != 7 && x != 8)
                count++;
            x++;
        }
    }
    cout << count;
}