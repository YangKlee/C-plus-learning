#include <iostream>
#include <math.h>
using namespace std;
int checkprime(int n, int i)
{
    if(n < 2)
    {
        return 0;
    }

    else 
    {
        if(i < 2)
        {
            return 1;
        }
        else
        {
            if(n%i == 0 && i!= n)
                return 0;
            return checkprime(n,i-1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    if(checkprime(n,n))
        cout << n << " la so nguyen to!";
    else
        cout << n << " khong phai la so nto";
}