#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,  m;
    cin >> n >> m;
    int input;
    vector <int> price_ticket;
    vector <int> max_price;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        price_ticket.push_back(input);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        max_price.push_back(input);
    }
    
    sort(price_ticket.begin(), price_ticket.end());
    //sort(max_price.begin(), max_price.end());
    int i = 0, j = 0, recert_price = -1;
    while(j <= max_price.size()-1)
    {
       if(max_price[j] >= price_ticket[i])
       {
            recert_price = price_ticket[i];
            //price_ticket.erase(i);
            i++;
       } 
       else if(max_price[j] < price_ticket[i] )
       {
            j++;
            cout << recert_price << endl;
            recert_price = -1;
       }
    }
}