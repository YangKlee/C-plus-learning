#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <long long> wApple;
    wApple.resize(n);
    long long sumWeight = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> wApple[i];
        sumWeight += wApple[i];
    }
    long long maxWeight_group;  
    if (sumWeight % 2 == 0)
        maxWeight_group = sumWeight / 2;
    else
        maxWeight_group = (sumWeight / 2) +1;
    sort(wApple.begin(), wApple.end(), greater());
    long long totalWeight_group = 0;
    for (int i = 0; i < wApple.size(); i++)
    {
        if (totalWeight_group + wApple[i] <= maxWeight_group)
        {
            totalWeight_group += wApple[i];
        }
    }
    cout << abs(totalWeight_group - (sumWeight - totalWeight_group)) << endl;   
    
}