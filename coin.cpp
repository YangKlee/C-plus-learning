#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> money;
    vector <int> result;
    int tmp;
    while(cin >> tmp)
    {
        money.push_back(tmp);
    }
    sort(money.begin(), money.end(), greater<int>());
    int i = 0;
    while(n > 0)
    {
        if(money[i] > n)
        {
            i++;
        }
        else
        {
            result.push_back(money[i]);
            n -= money[i];
        }
    }
    for(int x: result)
    {
        cout << x << ' ';
    }

}