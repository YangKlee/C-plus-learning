#include <bits/stdc++.h>
using namespace std;
bool SoHoanThien(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if(n%i == 0)
            sum += i;
    }
    if(sum == n)
        return 1;
    return 0;
    
}
int main()
{
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    // kiem tra so hoan thien nho nhat
    int max = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(SoHoanThien(a[i]) && a[i] > max)
            max = a[i];
    }
    cout << max << endl;
    
    
}