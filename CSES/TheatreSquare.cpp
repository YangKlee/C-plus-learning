#include <bits\stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n, a;
    cin >> n >> m >> a;
    long long Num_Square_n = 0;
    long long Num_Square_m = 0;
    if(n > 0)
    {
        Num_Square_n += n/a;
        if(n% a != 0)
        {
            Num_Square_n++;
        }
    }

    if((m-a)> 0)
    {
        Num_Square_m += m/a;
        if(m%a != 0)
            Num_Square_m++;
    }
    if(Num_Square_m == 0)
        Num_Square_m = 1;
    else if(Num_Square_n == 0)
        Num_Square_n == 1;
    cout << (long long)Num_Square_n*(long long)Num_Square_m << endl;


}
