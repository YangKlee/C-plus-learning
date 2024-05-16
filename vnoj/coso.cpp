#include<bits/stdc++.h>
using namespace std;
vector <long long> chuyencoso(long long n, long long hs)
{
    vector <long long> tmp;
    while(n > 0)
    {
        tmp.push_back(n%hs);
        n /= hs;
    }
    return tmp;
}
int main()
{
    long long n; cin >> n;
    vector <long long> coso2;
    vector <long long> coso8;
    vector <long long> coso16;
    coso2 = chuyencoso(n,2);
    coso8 = chuyencoso(n,8);
    coso16 = chuyencoso(n,16);
    for(int i = coso2.size()-1; i >= 0; i--)
    {
        cout << coso2[i] ;
    }
    cout << '\n';
    for(int i = coso8.size()-1; i >= 0; i--)
    {
        cout << coso8[i];
    }
    cout << '\n';
    for(int i = coso16.size()-1; i >= 0; i--)
    {
        if(coso16[i] > 9)
        {
            cout << (char)(coso16[i]- 10 + 65);
        }
        else
        {
            cout << coso16[i];
        }
    }
    cout << '\n';

}