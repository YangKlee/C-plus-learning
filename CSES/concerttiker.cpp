#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector <int> h;
    vector <int> t;
    for(int i= 0; i < n ; i++)
    {
        int tmp; cin >> tmp;
        h.push_back(tmp);
    }
    for(int i= 0; i < m ; i++)
    {
        int tmp; cin >> tmp;
        t.push_back(tmp);
    }
    sort(h.begin(), h.end());
    int i = 0, j = 0, last_min = -1;
    while(j < m)
    {
        //cout << i << ' ' << j << endl;
        if(h[i] == t[j])
        {
            cout << h[i] << endl;
            h.erase(h.begin()+i);
            n -= 1;
            //cout << "del: "<<h[i]<<endl;
            j++;
            i = 0;
        }
        else if(h[i] < t[j] && i < n)
        {
            last_min = i;
            i++;
        }
        else
        {
            if(last_min == -1 || h[last_min] > t[j])
                cout << -1 << endl;
            else
            {
                cout << h[last_min]<< endl;
                h.erase(h.begin()+last_min);
                n -= 1;
                //cout << "del: "<<h[last_min]<<endl;
            }
            last_min = -1;
            j++;
            i = 0;
        }
    }
}