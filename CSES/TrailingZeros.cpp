#include <bits/stdc++.h>
long long mod = 1e9;
using namespace std;

int main()
{
    int n, count = 0; 
    cin >> n;
    int k = 5;
    while(n/k != 0)
    {
        count += n/k;
        k *= 5;

    }
    cout << count;
    

}