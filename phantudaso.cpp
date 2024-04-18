#include<bits/stdc++.h>
using namespace std;
int ptudaso(vector <int> a, int l , int privot)
{
    int count = 1;
    for (int i = l; i < a.size(); i++)
    {
        if(count == 0)
        {
            return ptudaso(a,l+1,a[l+1]);
            break;
        }
        else if(a[i] == privot) count++;
        else count--;
    }
    return privot;
    
}
int main()
{
    int n; cin >> n;
    vector <int> a;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    cout << ptudaso(a,1, a[0]);
}