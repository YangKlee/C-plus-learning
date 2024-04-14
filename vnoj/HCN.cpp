#include<bits/stdc++.h>
using namespace std;
struct HCN
{
    int x;
    int y;
};

int main()
{
    struct HCN h1_duoi , h1_tren, h2_duoi, h2_tren, giao_tren, giao_duoi;
    //first : x; second y
    cin >> h1_duoi.x >> h1_duoi.y;
    cin >> h1_tren.x >> h1_tren.y;
    cin >> h2_duoi.x >> h2_duoi.y;
    cin >> h2_tren.x >> h2_tren.y;
    int dt_h1 = (h1_tren.x-h1_duoi.x)*(h1_tren.y - h1_duoi.y);
    int dt_h2 = (h2_tren.x-h2_duoi.x)*(h2_tren.y - h2_duoi.y);
    if(h1_duoi.x <= h2_duoi.x && h1_tren.x >= h2_duoi.x &&h1_duoi.y <= h2_duoi.y && h1_tren.y >= h2_duoi.y )
    {
        giao_duoi.x = h2_duoi.x;
        giao_duoi.y = h2_duoi.y;
        cout << giao_duoi.x << ' ' << giao_duoi.y << endl;
    }
    if(h2_duoi.x <= h1_tren.x && h2_tren.x >= h1_tren.x &&h2_duoi.y <= h1_tren.y && h2_tren.y >= h1_tren.y )
    {
        giao_tren.x = h1_tren.x;
        giao_tren.y = h1_tren.y;
        cout << giao_tren.x << ' ' << giao_tren.y << endl;
    }
    int dt_giao = (giao_tren.x - giao_duoi.x)*(giao_tren.y - giao_duoi.y);
    cout<< dt_h1 << ' ' << dt_h2 << ' '<< dt_giao << endl; 
    cout << dt_h1 - dt_giao + dt_h2 - dt_giao;
    
}