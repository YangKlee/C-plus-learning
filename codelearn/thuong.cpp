#include<bits/stdc++.h>
using namespace std;
bool isvohan(int n)
{
    for(int i = 2; i <= n; i++)
    {
        cout << i << endl;
        if(n%i == 0 && i!=2  && i!= 5)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a, b;
    cin >> a >> b;
    if(isvohan(b))
        cout << (float)a/(float)b;
    else
    {
        float x = (float)a/(float)b;
        cout << (int)x << "." << '(' << (x - (int)x)*10 << ')';
    }
}