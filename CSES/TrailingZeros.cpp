#include <bits/stdc++.h>
using namespace std;
long long giaithua(long long n)
{
    if(n == 1)
        return 1;
    else
        return n * giaithua(n-1);
}
int main()
{
    long long n, gt;
    cin >> n;
    int dem = 0;
    gt= giaithua(n);
    while(gt %10== 0)
    {
        if(gt %10== 0)
        {
            dem++;
            gt /= 10;
        }

        else
            break;
    }
    cout << dem;
    

}