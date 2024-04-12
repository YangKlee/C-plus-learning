#include<bits/stdc++.h>
using namespace std;
int recentX(vector <int> a, int x)
{
    int min = abs(a[0]- x);
    int num_recentX= a[0];
    for(int k:a)
    {
        if(abs(k-x) < min)
        {
            min = abs(k-x);
            num_recentX = k;
        }
    }
    return num_recentX;
}
int main()
{
    int n , x;
    cin >> n >> x;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << recentX(a,x);
    
}