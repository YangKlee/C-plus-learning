#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp - 2010 >= 0)
        {
            cout << tmp - 2010;
        }
        else
        {
            cout << abs(tmp - 2010) << "TTL";
        }

    }
    
}