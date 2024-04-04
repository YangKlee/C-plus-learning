#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long result = 1;
    for (long long i = n; i >= 1; i--)
    {
        result *= i;
    }
    cout << result;
    
}