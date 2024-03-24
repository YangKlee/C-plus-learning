#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    set<long long> a;
    int num  = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a.insert(x);
    }
    cout << a.size();
    
}