#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int>a;
    vector <int>b;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    b = a;
    sort(b.begin(), b.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        for(int j = 0; j < a.size(); j++)
        {
            //cout << b[x] << ' '<< a[j] << endl;
            if(b[x] == a[j])
            {
                cout << j << endl;
                break;
            }
        }
    }
    

    
}