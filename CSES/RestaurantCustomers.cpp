#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <pair<int, int>> timecustomer;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        timecustomer.push_back(make_pair(a,b));
    }
    int cout = 0;
    sort(timecustomer.begin(), timecustomer.end());
    for(auto x: timecustomer)
    {
        
    }

    
}