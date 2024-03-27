#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int count_lines = 0;
    cin >> n;
    vector <int> one, two;
    if(((n*(n+1))/2)%2 == 0)
    {
        cout << "YES" << endl;
        if(n%2 == 0)
        {
            cout << n/2 << '\n';
            for (int i = 1; i <= n/2; i++)
            {
                //cout <<"count = " <<count_lines << endl;

                cout << i << ' ' << n-i+1 << ' ';
                count_lines += 2;
                if(count_lines == (n/2))
                {
                    cout << '\n' << n/2 << '\n';
                }
                
            } 
        }
        else
        {
            cout << (n/2)+1 << '\n';
            for (int i = 1; i <= n/2; i++)
            {
                cout << i << ' ' << n-i << ' ';
                count_lines += 2;
                if(count_lines == (int)(n/2)+1)
                {
                    cout << '\n' << n/2 << '\n';
                }
                
            }
            cout << n;
        }
    }
    else
        cout << "NO" << endl;
}