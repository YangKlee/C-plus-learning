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
    float min_diff = fabs(diff[1] - diff[0]);
    for (int i = 1; i < n; i++)
    {
        float tmp = fabs(diff[i-1] - diff[i]);
        if(tmp < min_diff)
        {
            min_diff = tmp;
        }
    }
    cout << min_diff;
    
    
}