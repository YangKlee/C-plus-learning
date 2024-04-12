#include<bits/stdc++.h>
using namespace std;
int main()
{
    //first : x; second y
    pair<int, int> h1_duoi;
    pair<int, int> h1_tren;
    pair<int, int> h2_duoi;
    pair<int, int> h2_tren;
    cin >> h1_duoi.first >> h1_duoi.second;
    cin >> h1_tren.first >> h1_tren.second;
    cin >> h2_duoi.first >> h2_duoi.second;
    cin >> h2_tren.first >> h2_tren.second;
    int ht_h1 = (h1_tren.first-h1_duoi.first)*(h1_tren.second - h1_duoi.second);
    int ht_h2 = (h2_tren.first-h2_duoi.first)*(h2_tren.second - h2_duoi.second);
    //cout<< ht_h1 << ' ' << ht_h2; 
    pair<int, int> temp;
    temp.first = max(h1_duoi.first, h2_duoi.first);
    temp.second = min(h1_tren.second, h2_tren.second);
    int S_ACB = (temp.first - h1_duoi.first) * (temp.second - h1_duoi.second);
    int S_ABDE = (temp.first - h2_duoi.first) * (temp.second - h2_duoi.second);
    cout << ht_h1 + ht_h2 - S_ACB - S_ABDE;
    
}