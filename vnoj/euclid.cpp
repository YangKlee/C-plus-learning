#include<bits/stdc++.h>
using namespace std;
struct ToaDo
{
    long long x;
    long long y;
};
float Euclid(ToaDo p, ToaDo q)
{
    long long x = (q.x - p.x)*(q.x - p.x) + (q.y - p.y)* (q.y - p.y);
    return sqrt(x);
}
int main()
{
    struct ToaDo a, b, c,d;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if(Euclid(a,b) == Euclid(c,d))
        {
            cout << "EQUA" << '\n';
        }
        else
        {
            cout << "NEQU" << '\n';
        }
    }

    
}