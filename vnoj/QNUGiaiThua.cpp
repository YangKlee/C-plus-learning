#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int count = 0;
    vector <int> a;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin>> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if(a[i]+a[j] <= x && i!=j)
            {
                count++;
            }
        }
        
    }
    cout << count;
        
}