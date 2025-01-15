#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
struct NV
{
    string hoTen;
    int namSinh;
    int soNamLV;
    float hsLuong;
    NV ()
    {
        this->hsLuong = 2.34;
    }
};

int main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    vector <NV> listNV(n);
    for (int i = 0; i < n; i++)
    {
        cin >> listNV[i].hoTen;
        cin >> listNV[i].namSinh;
        cin >> listNV[i].soNamLV;
        cin >> listNV[i].hsLuong;
    }
    // query
    for (int i = 0; i < q; i++)
    {
        char index;
        cin >> index;
        if (index == 'C')
        {
            cout << listNV.size() << endl;
        }
        else if (index == 'F')
        {
            string name;
            cin >> name;
            int count = 0;
            for (int i = 0; i < listNV.size(); i++)
            {
                if (name == listNV[i].hoTen)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if (index == 'S')
        {
            int year;
            cin >> year;
            int count = 0;
            for (int i = 0; i < listNV.size(); i++)
            {
                if (listNV[i].soNamLV >= year)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if (index == 'I')
        {
            NV tmpNV;
            cin >> tmpNV.hoTen;
            cin >> tmpNV.namSinh;
            tmpNV.soNamLV = 0;
            listNV.push_back(tmpNV);
        }
    }
}