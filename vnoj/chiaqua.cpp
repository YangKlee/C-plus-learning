#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long count_100 = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        if(tmp == 100) count_100++;
    }
    long long count_200 = 1LL*n - count_100 ;
    if(count_100 == 0 && count_200 %2 == 0)
    {
        cout << "YES";
    }
    else if(count_200 == 0 && count_100 %2 == 0)
    {
        cout << "YES";
    }
    else
    {
        count_100 *= 100;
        count_200 *= 200;
        if(count_200 % count_100  || count_100 % count_200)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }

    
}