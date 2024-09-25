#include <bits/stdc++.h>
using namespace std;
int tongChuSo(long long n)
{
    if (n < 10)
        return n;
    else 
    {
        return n%10 + tongChuSo(n/10);
    }
}
int tongChuSoAm(long long n)
{
    //cout << n << endl;
    if (n < 10)
    {
        //cout << n * -1 << endl;
        return n * -1;
    }
    else 
    {
        
        return n%10 + tongChuSoAm(n/10);
    }
}
int main()
{
    long long n;
    cin >> n;
    int result = 0;
    if(n >= 0)
        result = tongChuSo(n);
    else
    {
        n = abs(n);
        result = tongChuSoAm(n);
    }
    cout << result;

}