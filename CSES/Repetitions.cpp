#include <bits/stdc++.h>
using namespace std;
int MaxReplace(string a)
{
    int sum = 1, max = 0;
    for (int i = 0; i < a.length()-1; i++)
    {
        if(a[i]!=a[i+1])
        {
            if(sum > max) max = sum;
            sum  = 0;
        }
        sum++;
    }
    if(sum > max)
        max = sum;
    return max;
    
}
int main()
{
    string ADN;
    cin >> ADN;
    cout << MaxReplace(ADN);
    
    
}