#include <bits/stdc++.h>
using namespace std;
void chuyenChuThuong(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
}
int main()
{
    string s;
    cin >> s;
    chuyenChuThuong(s);
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] != 'u'&& s[i] != 'e' &&s[i] != 'o' &&s[i] != 'a' &&s[i] != 'i')
            cout << '.' << s[i];
        if(s[i] == ' ')
            cout << " ";
    }

}