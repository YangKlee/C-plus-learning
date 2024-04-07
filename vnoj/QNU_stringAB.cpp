#include<bits/stdc++.h>
using namespace std;
string xau_AB(string a, string b)
{
    
    if(a.length() >= b.length())
    {
        return a;
    }
    else
    {
        a.insert(a.begin(),'A');
        cout << a << endl;
        string chuoidao = a;
        if(a.length() >= b.length())
        {
            return a;
        }
        reverse(chuoidao.begin(), chuoidao.end());
        chuoidao.insert(chuoidao.begin() , 'B');
        cout << chuoidao << endl;
        return xau_AB(chuoidao,b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("xauab.inp","r",stdin);
    //freopen("xauab.out","w",stdout);
    string a, b;
    cin >> a>> b;

    if(xau_AB(a,b) == b)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

}