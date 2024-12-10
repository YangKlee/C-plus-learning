#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
using namespace std;
struct HocVien
{
    string maHV;
    string maLop;
    int mucHocPhi;
    bool isNopHP;
    void dongHocPhi()
    {
        if (this->isNopHP != true)
        {
            this->isNopHP = true;
            cout << "Nop hoc phi thanh cong" << endl;
        }
        else
            cout << "Da nop hoc phi roi" << endl;
    }
    void inThongTin()
    {
        cout << maHV << ";" << maLop << ";" << mucHocPhi <<";" << isNopHP << endl;
    }
};
void nhapThongTin(vector <HocVien> &dsHV)
{
    HocVien hvTemp;
    cout << "Nhap ma hoc vien : " ;
    //cin.ignore(1);
    cin >>  hvTemp.maHV;
    cout << "Nhap ma lop hoc : " ;
    //cin.ignore(1);
     cin >> hvTemp.maLop;
    cout << "Nhap muc hoc phi : " ;
    //cin.ignore(1);
    cin >> hvTemp.mucHocPhi;
    hvTemp.isNopHP = false;
    dsHV.push_back(hvTemp);
}
bool nopHocPhi(vector <HocVien> &dsHV)
{
    string maHV_inp;
    cout << "Nhap ma hoc vien can nop hoc phi: ";
    cin >> maHV_inp;
    cout << "MHV: " << maHV_inp << endl;
    for (int i = 0; i < dsHV.size(); i++)
    {
        if (maHV_inp == dsHV[i].maHV)
        {
            dsHV[i].dongHocPhi();
            return 1;
        }
    }
    return 0;
}
void save(vector <HocVien> dsHV)
{
    ofstream f("data.dat");
    try
    {
        
        f << dsHV.size() << "\n";
        for (int i = 0; i < dsHV.size(); i++)
        {
            f << dsHV[i].maHV << ";" << dsHV[i].maLop << ";" << dsHV[i].mucHocPhi <<";" << dsHV[i].isNopHP <<"\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "Loi ghi file" << endl;
    }
    f.close();
    


}
void showMenu()
{
    char input;
    vector <HocVien> dsHV;
    do
    {
        
        cout << "1. Nhap danh sach hoc vien" << endl;
        cout << "2. Nop hoc phi" << endl;
        cout << "3. Danh sach chua nop hoc phi" << endl;
        cout << "4. Luu tru" << endl;
        cout << "5. Thoat" << endl;
        cout << "Vui long nhap lua chon : ";
      //cin.ignore(1);
        input = _getch();
        //cin.ignore(1);
        cout << "\n";
        if (input == '1')
        {
            nhapThongTin(dsHV);
        }
        if (input == '2')
        {
            if (!nopHocPhi(dsHV))
                cout << "Ma hoc vien khong hop le" << endl;
        }
        if (input == '3')
        {
            cout << "Danh sach hoc vien chua nop hoc phi: " << endl;
            for (int i = 0; i < dsHV.size(); i++)
            {
                if (!dsHV[i].isNopHP)
                    dsHV[i].inThongTin();
            }
        }
        if (input == '4')
        {
            save(dsHV);
        }
        if (input == '5')
            exit(1);
    } while (input != 27);

}
int main()
{
    showMenu();
}