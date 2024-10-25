#include <bits/stdc++.h>
using namespace std;
class NhanVien
{
private:
    string ten;
    int namSinh;
    int soNamLamViec;
    float heSoLuong;
public:
    NhanVien(){};
    NhanVien(string ten, int namSinh) // constuctor
    {
        this->ten = ten;
        this->namSinh = namSinh;
        this->soNamLamViec = 0;
        this->heSoLuong = 2.34;
        
    }
    NhanVien(string ten, int namSinh, int soNamLamViec, float heSoLuong) // constuctor
    {
        this->ten = ten;
        this->namSinh = namSinh;
        this->soNamLamViec = soNamLamViec;
        this->heSoLuong = heSoLuong;
        
    }
    int getSoNamLamViec()
    {
        return this ->soNamLamViec;
    }
    string getName()
    {    
        return this -> ten;
    }
};
int main()
{
    int n, q;
    //int slnv = 0;
    cin >> n >> q;
    //NhanVien *dsnv = new NhanVien[100000];
    vector <NhanVien> dsnv(n);
    for (int i = 0; i < n; i++)
    {
        string ten;
        int namSinh;
        int soNamLamViec;
        float heSoLuong;
        cin >> ten >> namSinh >> soNamLamViec >> heSoLuong;
        dsnv[i] = NhanVien(ten, namSinh, soNamLamViec, heSoLuong);
        //slnv++;
    }
    // query
    for (int i = 0; i < q; i++)
    {
        string argument_first ;
        cin >> argument_first;
        if (argument_first == "I")
        {
            string arg_name;
            int arg_year;
            cin >> arg_name >> arg_year;
            //dsnv[n] = NhanVien(arg_name, arg_year);
            dsnv.push_back(NhanVien(arg_name, arg_year));
            //n++;
        }
        else if(argument_first == "C")
        {
            cout << dsnv.size() << "\n";
        }
        else if(argument_first == "S")
        {
            int x, count = 0;
            cin >> x;
            for (int i = 0; i < dsnv.size(); i++)
            {
                if(dsnv[i].getSoNamLamViec() >= x)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if(argument_first == "F")
        {
            string arg_name;
            int dem = 0;
            cin >> arg_name;
            for (int i = 0 ; i < dsnv.size(); i++)
            {
                if (dsnv[i].getName() == arg_name)
                    dem++;
            }
            cout << dem << endl;
        }
    }
}