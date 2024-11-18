#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    int n_boi3 = 3;
    int n_boi5 = 5;
    int n_boi35 = 3*5;
    for (int i = 3; i < n ; i+=n_boi3)
    {
        sum += i;
    }
    for (int i = 5; i < n ; i+=n_boi5)
    {
        sum += i;
    }
    for (int i = 3*5; i < n ; i+=n_boi35)
    {
        sum -= i;
    }
    cout << sum  << endl;
}