#include<bits/stdc++.h>
using namespace std;
int magicCalculator(int a, int b)
{
    int count = 0;
    unsigned long long x = pow((long long)a,(long long)b);
    cout << x << endl;
    while(x >0)
    {
        count++;
        x /= 10LL;
    }
    cout << x << endl;
    return count;
}
int main()
{
    int a, b;
    cin >> a>>b;
    cout << magicCalculator(a,b);
}