#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
using namespace std;
int main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    vector<int> price(n);
    for(int i = 0; i < price.size(); i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < q; i++)
    {
        int k, l, r;
        cin >> k >> l >> r;
        l--; r--;
        vector<int> xuly = price;
        int result = 0;
        sort(xuly.begin()+l, xuly.begin()+r);
        for(int i = l; i < r+k  && i - l < k; i++)
        {
            result += xuly[i];
        }
        cout << result << endl;
    }

}   