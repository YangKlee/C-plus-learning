#include <bits/stdc++.h>
using namespace std;
bool checkPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
    
}
int revert_num(int n, int songuoc)
{
    if(n == 0)
        return songuoc;
    else
    {
        songuoc = songuoc *  10 + n%10; 
        return revert_num(n/10,songuoc);
    }
        
}
int main()
{
    int a, b, count = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        //cout << revert_num(i,0)<< endl;
        if(checkPrime(i) == true&& revert_num(i,0) == i)
            count++;
    }
    cout << count;
    
}