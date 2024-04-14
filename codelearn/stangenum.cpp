#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = n;
    int count = 0;
    while(x < 0)
    {
        count++;
        x =  x /10;
    }
    x = n;
    int sum = 0;
    while( x < 0)
    {
        cout << x        sum += pow(x%10, count);
        x = x / 10;
    }
    
    if(sum == n)
    {
        cout << "Yes";
    }
    else cout << "No";
}