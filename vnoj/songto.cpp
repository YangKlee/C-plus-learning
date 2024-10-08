#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n)
{
    if(n < 2 )
        return 0;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        if(isPrime(tmp))
            cout << tmp << "\n";
    }
}