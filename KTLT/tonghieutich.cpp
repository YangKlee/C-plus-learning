#include <bits/stdc++.h>
using namespace std;
string nhanMotChuSo(string n, char x)
{
    if(x == '0')
        return "0";
    string result = "";
    int m = 0;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        char tmp = char(n[i] - 48) * char(x - 48);
        if (m != 0)
        {   tmp += m;
            m = 0;
        }
        if (tmp >= 10)
        {
            m = tmp / 10;
            tmp = tmp % 10;
        }
        else
            m = 0;
        result.insert(result.begin(), (tmp + 48));
    }
    if (m != 0)
        result.insert(result.begin(), char(m + 48));
    return result;
}
string congChuoi(string a, string b)
{
    while(a.size() < b.size()) 
        a.insert(a.begin(), '0');
    while(a.size() > b.size())
        b.insert(b.begin(), '0');
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
string nhanHaiChuSo(string a, string b)
{
    string result = "0";
    string tmp1 =  "";
    //string tmp2 = "";
    while(a.size() < b.size()) 
        a.insert(a.begin(), '0');
    while(a.size() > b.size())
        b.insert(b.begin(), '0');
    int count = 0;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        tmp1 = nhanMotChuSo(a, b[i]);
        for (int j = 0; j < count; j++)
        {
            tmp1.push_back('0');
        }
        result =  congChuoi(result, tmp1);
        count++;
    }
    return result;
}
string hieuChuoi(string a, string b)
{
    string result = "";
    
    int nho = 0;
    bool isMuon = false;
    bool isAm = false;
    //string tmp2 = "";
    while(a.size() < b.size()) 
        a.insert(a.begin(), '0');
    while(a.size() > b.size())
        b.insert(b.begin(), '0');
    for (int i = a.size() - 1; i >= 0; i--)
    {
        char tmp;
        if (char(a[i] - 48) >= char(b[i] - 48))
            tmp = char(a[i] - 48) - char(b[i] - 48);
        else
        {
            tmp = char(a[i] - 48 ) + 10 - char(b[i] - 48);
            isMuon = true;
        }
        if (tmp < 0)
        {
            if (isAm ==  false)
                isAm == true;
            else
                isAm = false;
            tmp = abs(tmp);
        }
        if (nho != 0)
        {
            tmp += nho;
            nho = 0;
        }
        if (tmp >= 10)
        {
            nho = tmp / 10;
            tmp = tmp % 10;
        }
        if (isMuon){
            nho --;
            isMuon = false;
        }
        else
            nho = 0;
        result.insert(result.begin(), char(tmp+48));
    }
    if(isAm)
        result.insert(result.begin(), '-');
    return result;
}
int main()
{
    string x;
    string y;
    cin >> x >> y;
    cout << congChuoi(x,y) << endl;
    cout << hieuChuoi(x, y) << endl;
    cout << nhanHaiChuSo(x,y) << endl;
}