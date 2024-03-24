#include <bits/stdc++.h>
using namespace std;
int Weird(long long n)
{
    if(n == 1)
    {
        cout <<n;
        return 1;
    }
    else
    {
        cout << n << " " ;
        if(n % 2 == 0)
            return Weird(n/2);
        else
            return Weird(n*3+1);
    }
}
int main()
{
    long long n;
    cin >> n;
    Weird(n);
    return 0;

}
