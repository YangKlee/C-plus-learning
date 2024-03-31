#include<bits\stdc++.h>
using namespace std;
bool CheckPerfectNumber(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if(n%i == 0)   
            sum+= i;
    }
    if(sum == n) return true;
    return false;
    
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if(CheckPerfectNumber(i))
            cout << i << ' ';
    }
    
}