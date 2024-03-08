#include <iostream>
#include <math.h>
using namespace std;
int checkprime(int n, int i)
{
    if(n <= 1)
    {
        return 0;
    }
    else 
    {
        if(n==i)
            return 1;
        else
        {
            if(n%i == 0)
                return 0;
            else
                return checkprime(n, i+1);
        } 
    }
}
int main()
{
    int n;
    cin >> n;
    if(checkprime(n,2))
        cout << n << " la so nguyen to!";
    else
        cout << n << " khong phai la so nto";
}