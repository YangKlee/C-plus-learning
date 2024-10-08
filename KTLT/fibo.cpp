#include <bits/stdc++.h>
using namespace std;
string congChuoi(string a, string b)
{
    if (a.length() != b.length())
    {
        while (a.length() < b.length())
        {
            a.insert( a.begin(), '0');
        }
        while (a.length() > b.length())
        {
            b.insert( b.begin(), '0');
        }
        //string out =  a + "\n" + b;
        //return out;
    }
    string result = "";
    char m = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {

        char tmp = 0;
        tmp = ((char)a[i] - (char)48) + ((char)b[i] - (char)48);
        if (m != 0)
        {
            tmp += m;
            m = 0;
        }
        else
            m = 0;
        if (tmp >= 10)
        {
            m = tmp / 10;
            tmp = tmp % 10 ;
        }
        result.insert(result.begin(),(char)tmp + (char)48);
    }
    if(m!= 0)
        result.insert(result.begin(),(char)m + (char)48);
    return result;
}
string tinhFiboN(long long n)
{
    //vector <unsigned long long> F(n);
    // truong hop co so
    string a = "0";
    string b = "1";
    string c = "";
    for (int i = 2; i <= n; i++)
    {
        c = congChuoi(a,b);
        a = b; b = c;
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin  >> n;
    cout << tinhFiboN(n);
}