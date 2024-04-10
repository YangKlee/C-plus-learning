#include<bits/stdc++.h>
using namespace std;
int sochuso(int n)
{
    if(n <= 9)
        return 1;
    else
    {
        return 1+sochuso(n/10);
    }
}
string StrangeNumber(int n)
{
    int k = n;
    int sum = 0;
    for(int i = 0; i < sochuso(n); i++)
    {
        sum += k%10;
        k /= 10;
    }
    for(int i = sum; i < n; i++)
    {
        if(n%10)
    }
}
int main()
{
    int n;
    cin >> n;
}