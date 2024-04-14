#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <long long> diff;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        diff.push_back(tmp);

    }
    sort(diff.begin(), diff.end());
    cout << diff[diff.size()-1] - diff[diff.size()-2];
    
}