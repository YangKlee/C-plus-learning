#include <bits/stdc++.h>
using namespace std;
void chuanHoa(string &s)
{
    int pos = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0')
        {
            if (pos == -1)
                return;
            else
                break;
        }
        else
        {
            pos = i;
        }
    }
    //cout << pos << endl;
    s.erase(s.begin(), s.begin()+ pos+1);
    if (s.length() == 0)
        s = "0";
}
string tongChuoi(string a, string b)
{
    string result = "";
    if (a.length() != b.length())
    {
        int maxlenght = max(a.length(), b.length());
        while (a.length() < maxlenght)
        {
            a = '0' + a;
        }
        while (b.length() < maxlenght)
        {
            b = '0' + b;
        }
    }
    char m = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        char sum = (a[i] - '0') + (b[i] - '0');
        sum += m;
        m = 0;
        if (sum >= 10)
        {
            m =  char(sum / 10);
            sum = sum % 10;
        }
        result.insert(result.begin(), char(sum + '0'));

    }
    if (m != 0)
    {
        result.insert(result.begin(), char(m + '0'));
    }
    return result;
}
bool soSanh(string a, string b)
{
    bool isBhonA = false;
    int isBang = 0;
    // tra ve true neu a lon hon b
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] < b[i])
        {
            return true;
        }
    }
    return isBhonA;
}
string hieuChuoi(string a, string b)
{
    char m = 0, isam = false;
    string result = "";
    if (a.length() != b.length())
    {
        if (b.length() > a.length())
         {   swap(a, b);
            isam = true;
         }
        int maxlenght = max(a.length(), b.length());
        while (a.length() < maxlenght)
        {
            a = '0' + a;
        }
        while (b.length() < maxlenght)
        {
            b = '0' + b;
        }
    }
    else
    {
        if (soSanh(a,b))
        {
            swap(a,b);
            isam = true;
        }
    }
    //cout << a << " "<< b << endl;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        char hieu =((a[i] - '0')) - (b[i] - '0');
        hieu -= m;
        m = 0;
        if (hieu < 0)
        {
            hieu += 10;
            m++;
        }
        else
            m = 0;
        result.insert(result.begin(), char(hieu + '0'));
        
    }
    if (result.length() > 1)
        chuanHoa(result);

    if (m != 0)
    {
        if (isam == true)
            isam == false;
        else
            isam == true;
    }
    if (isam == true)
    {
        result.insert(result.begin(), '-');
    }
  
    
    return result;
}
string nhanMotChuSo(string a, char b)
{
    char m = 0;
    string result = "";
    for (int i = a.length() - 1; i >= 0; i--)
    {
        char tich = (a[i] - '0') * (b - '0');
        tich += m;
        m = 0;
        if (tich >= 10)
        {
            m = tich / 10;
            tich = tich % 10;
        }
        result.insert(result.begin(), char(tich + '0'));
    }
    if (m != 0)
        result.insert(result.begin(), (m + '0'));
    return result;
}
string nhanChuoi(string a, string b)
{
    int hang = 0;
    string result = "";
    for (int i = b.length() - 1; i >= 0; i --)
    {
        string tmp = nhanMotChuSo(a, b[i]);
        for (int k = 1; k <= hang; k++)
        {
            tmp = tmp + "0";
        }
        result = tongChuoi(tmp, result);
        hang++;
    }
    return result;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << tongChuoi(a,b) << endl;
    cout << hieuChuoi(a,b) << endl;
    cout << nhanChuoi(a,b) << endl;


}