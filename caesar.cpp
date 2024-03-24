#include <iostream>
#include <string>
using namespace std;

string chuyenChuHoa(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z' )
        {
            s[i] -= char(32);
        }
    }
    return s;
    
}
string CaesarCryptor(string s, int k)
{
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>= 'A' && s[i] <= 'Z')
        {
            s[i] += k;
            if((char)s[i] > 'Z')
            {
                s[i] = (char)s[i] - 90 + 64;
            }
        }
    }
    return s;
    
}
int main()
{
    string s;
    int k;

    do
    {
        cout << "Nhap sau s (khong qua 100 ky tu): ";
        getline(cin, s);
    } while (s.length() > 100);
    do
    {
        cout << "Nhap k (0<k20)";
        cin >> k;
    } while (k < 0 || k >20);
    
    s = chuyenChuHoa(s);
    s = CaesarCryptor(s,k);
    cout << s << endl;


}