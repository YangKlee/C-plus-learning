#include <bits/stdc++.h>
using namespace std;
class NhanVien
{
private:
    string hoTen;
    int namSinh;
    int soNamLamViec;
    float heSoLuong;
public:
    NhanVien(string hoTen, int namSinh, int soNamLamViec, float heSoLuong)
    {
        this->hoTen = hoTen;
        this->namSinh = namSinh;
        this->soNamLamViec = soNamLamViec;
        this->heSoLuong = heSoLuong;
    }
    NhanVien(string hoTen, int namSinh)
    {
        this->hoTen = hoTen;
        this->namSinh = namSinh;
        this->soNamLamViec = 0;
        this->heSoLuong = 0;
    }
    string getTenNV()
    {
        return this->hoTen;
    }
    int getNamLamViec()
    {
        return this ->soNamLamViec;
    }
};
vector <NhanVien> nhapData(vector <NhanVien> dsnv, int n)
{
    string hoTen;
    int namSinh;
    int soNamLamViec;
    float heSoLuong;
    for (int i = 0; i < n; i++)
    {
        cin >> hoTen >> namSinh >> soNamLamViec >> heSoLuong;
        dsnv.push_back(NhanVien(hoTen, namSinh, soNamLamViec, heSoLuong));
    }
    return dsnv;
}
int queryTenNV(vector <NhanVien> dsnv, string name)
{
    int count = 0;
    for (int i = 0; i < dsnv.size(); i++)
    {
        if (dsnv[i].getTenNV() == name)
        {
            count++;
        }
    }
    return count;
}
int queryNamLamViec(vector <NhanVien> dsnv, int nam)
{
    int count = 0;
    for (int i = 0; i < dsnv.size(); i++)
    {
        if (dsnv[i].getNamLamViec() >= nam)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector <NhanVien> dsnv;
    dsnv= nhapData(dsnv, n);
    char first_arg;
    for (int i = 0; i < q; i++)
    {
        cin >> first_arg;
        if (first_arg == 'C')
            cout << dsnv.size() << "\n";
        else if (first_arg == 'F')
        {
            string ten;
            cin >> ten;
            cout << queryTenNV(dsnv, ten) << "\n";
        }
        else if(first_arg == 'S')
        {
            int x;
            cin >> x;
            cout << queryNamLamViec(dsnv, x) << "\n";
        }
        else if(first_arg == 'I')
        {
            string name;
            int year;
            cin >> name >> year;
            dsnv.push_back(NhanVien(name, year));
        }
    }
}