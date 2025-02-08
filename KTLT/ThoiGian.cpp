#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
struct Date
{
    int d;
    int m;
    int y;
    bool isNamNhuan()
    {
        if (y % 4 == 0)
        {
            if (y% 400 == 0 || y% 100 != 0)
            {
                return true;
            }
        }
        return false;
    }
    bool isThang30()
    {
        if (m == 4|| m== 6|| m == 9|| m == 11)
        {
            return true;
        }
        return false;
    }
    bool isThang31()
    {
        if (!isThang30() && m!= 2)
            return true;
        return false;
    }
    bool isHopLe()
    {
        if (d > 30 && isThang30())
            return false;
        else if (d> 31 || d < 1)
            return false;
        else if (!isNamNhuan() && m == 2 && d > 28)
            return false;
        else if (m > 12 || m < 1)
            return false;
        return true;
    }
    void toString()
    {
        cout << d << '/' << m << '/' << y << endl;
    }
};

Date congNgay(Date d, int n)
{
    while(n)
    {
        d.d += 1;
        if ((d.isThang30() && d.d > 30) || (d.isThang31() && d.d > 31))
        {
            d.d = 1;
            d.m +=1;
        }
        else if ((d.isNamNhuan() && d.d > 29 && d.m == 2) || (!d.isNamNhuan() && d.d > 28 && d.m == 2))
        {
            d.d = 1;
            d.m +=1;
        }
        if (d.m > 12)
        {
            d.m = 1;
            d.y +=1;
        }
        n--;
    }
    return d;
}
int main()
{
    Date d ;
    cin >> d.d >> d.m >> d.y;
    int n; cin >> n;
    Date dres = congNgay(d, n);
    //d.toString();
    dres.toString();
}