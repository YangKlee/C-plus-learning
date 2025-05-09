#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
using namespace std;


vector<vector<int>> result;
void bk(int index, int t, vector<int>child, vector<int>a)
{
    int sum = 0;
    for(int i: child)
    {
        sum+= i;
    }
    if(sum == t)
    {
        result.pb(child);
    }
    for (int i = index; i < a.size(); i++)
    {
        child.pb(a[i]);
        bk(i+1,t, child, a);
        child.pop_back();

    }
}
int main()
{
    IOS;
    int n, t;
    cin >> n>> t;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> tmp;
    bk(0, t, tmp, a);
    cout << result.size() << endl;
    for(vector<int> vt: result)
    {
        sort(vt.begin(), vt.end());
        for(int i: vt){
            cout << i << " ";
        }
        cout << endl;
    }


}