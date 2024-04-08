#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, count = 0;
    vector <int> cuc;
    vector <int> mai;
    freopen("muahoa.inp","r",stdin);
    freopen("muahoa.out","w",stdout);
    while(count < 5)
    {
        cin >> n;
        if(count < 3)
        {
            cuc.push_back(n);
        }
        else
        {
            mai.push_back(n);
        }
        count++;
    }
    sort(cuc.begin(), cuc.end());
    sort(mai.begin(), mai.end());
    cout << cuc[0]+mai[0]-50;
    
}