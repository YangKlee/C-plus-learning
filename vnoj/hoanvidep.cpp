#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool stack = false;
    if(n <= 3 and n !=1)
    {
        cout << "NO SOLUTION"<< endl;
        exit(0);
    }
    for (int i = 1; i <= n; i++)
    {
        if(stack == true)
        {
            if(i%2 != 0)
            {
                cout << i << ' ' ;
            }
        }
        else
        {
            if(i%2 == 0)
            {
                cout << i << ' ';
            }
            if(i == n)
            {
                stack = true;
                i = 0;
            }
        }
    }
    
    
}