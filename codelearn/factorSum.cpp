#include <bits/stdc++.h>
using namespace std;
bool checkPrime(int n)
{
    if(n< 2) return 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}
int factorSum(int n)
{
    int sum;
    int last;
    int last1;
    int stack = 0;
    while(n != 1)
    {
        //cout << n;
        sum = 0;
        //int tmp = n;
        for (int i = 2; i <= n; i++)
        {
            if(checkPrime(i) && n%i == 0)
            {
                //cout << i;
                sum += i;
                n /= i;
                i = 1;
            }
        }
        n = sum;
        if(stack == 0)
        {
            last = n;
            stack = 1;
        }
        else
        {
            last1 = n;
            stack = 0;
        }
        if(last1 == last)
            break;
    }
    return sum;
    
}
int main()
{
    int n;
    cin >> n;
    cout << factorSum(n);
    
}