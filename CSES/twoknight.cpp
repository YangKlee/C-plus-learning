#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        long long tongcacbuoc = ((i*i)*(i*i-1))/2;
        long long cacbuoctancong = 4*(i-1)*(i-2);
        cout << tongcacbuoc - cacbuoctancong << endl;
    }
    
}