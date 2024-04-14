#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float delta = (b*b) - 4*a*c;
    vector <float> nghiem;
    if(delta < 0)
    {
        cout << "VN";
    }
    else
    {
        nghiem.push_back(((-b)+ sqrt(b*b - 4*a*c))/(2*a));
        nghiem.push_back(((-b)- sqrt(b*b - 4*a*c))/(2*a));
        sort(nghiem.begin(), nghiem.end());
        for(float x: nghiem)
        {
            cout << fixed << setprecision(2);
            cout << x << endl;
        }
    }
}