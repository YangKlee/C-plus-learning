#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
    
}