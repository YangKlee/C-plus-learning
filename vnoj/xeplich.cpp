#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <pair<int, int>> time;
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        time.push_back(make_pair(a,b));
    }
    pair <int, int> totaltime;
    totaltime.first = time[0].first;
    totaltime.second = time[0].second;
    int sum = 0;
    int diff;
    sort(time.begin(), time.end());
    for(auto values:time)
    {
        cout << values.first << ' ' << values.second << endl;
    }
    cout << sum;

}