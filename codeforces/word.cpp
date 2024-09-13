#include <bits/stdc++.h>
using namespace std;
string ChuyenHoaThuong(string s,int x)
{
     for(int i = 0; i < s.length(); i++)
     {
        if((char)s[i] >= 'A' && (char)s[i] <= 'Z')
            s[i]= (char)s[i]+(char)x;
        else if((char)s[i] >= 'a' && (char)s[i] <= 'z')

     }
     return s;
}
int main()
{
    string s;
    cin >> s;
    int hoa = 0;
    int thuong = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if((char)s[i] >= 'A' && (char)s[i] <= 'Z')
            hoa++;
        else if((char)s[i] >= 'a' && (char)s[i] <= 'z')
            thuong++;
    }
    if(hoa > thuong)
    {
        cout << ChuyenHoaThuong(s,-32);
    }
    else if(hoa <= thuong)
    {
        cout << ChuyenHoaThuong(s,32);
    }



}
