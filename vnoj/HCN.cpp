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
    cout<< ht_h1 << ' ' << ht_h2; 
}