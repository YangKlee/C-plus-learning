#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,  m;
    cin >> n >> m;
    int input;
    vector <int> price_ticket;
    vector <int> max_price;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        price_ticket.push_back(input);
    }
    vector<int>::iterator it;
    sort(price_ticket.begin(), price_ticket.end(), greater<int>());
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        it = lower_bound(price_ticket.begin(), price_ticket.end(), input, greater<int>());
        if(it == price_ticket.end() )
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
        }
        price_ticket.erase(it);
    }
    
    
}