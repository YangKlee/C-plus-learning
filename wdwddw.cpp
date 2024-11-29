#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

using namespace std;

struct hocVien {
    string maHV;
    string maLop;
    double mucHP;
    bool daNopHP;
};

//Nhap danh sach
void nhapDanhSach(vector <hocVien>& dsHV) {
    hocVien hv;
    fflush(stdin);
    cout << "Nhap ma hoc vien: ";
    cin >> hv.maHV;
    fflush(stdin);
    cout << "Nhap ma lop: ";
    cin >> hv.maLop;
    fflush(stdin);
    cout << "Nhap muc hoc phi: ";
    cin >> hv.mucHP;
    hv.daNopHP = false;
    dsHV.push_back(hv);
    cout << "Nhap thanh cong." << endl;

}

//Nop hoc phi
void nopHocPhi(vector <hocVien>& dsHV) {
    bool found = false;
    string maHV;
    cout << "Nhap ma hoc vien";
    cin >> maHV;
    for (auto& a : dsHV) {
        if (a.maHV == maHV) {
            found = true;
            if (!a.daNopHP) {
                a.daNopHP = true;
                cout << "Da nop hoc phi." << endl;
            }
            else {
                cout << "Da nop hoc phi roi." << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "Ma sinh vien khong ton tai." << endl;
    }
}

// danh sach chua nop hoc phi
void chuaNop(vector <hocVien>& dsHV) {
    for (auto& a : dsHV) {
        if (!a.daNopHP) {
            cout << a.maHV << " " << a.maLop << " " << a.mucHP << endl;
        }
    }
}
//Ham lưu vào file
void save(vector <hocVien>& dsHV) {
    ofstream file  ("HocVien.dat");
        file << dsHV.size() << "\n";
        for (auto& a : dsHV) {
            file << a.maHV << " " << a.maLop << " " << a.mucHP << " " << a.daNopHP << "\n";
        }
        file.close();
        cout << "Da luu thanh cong";
}

void hienThiMenu() {
    vector<hocVien> ds;
    while (true) {
        cout << "------------Menu--------------" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. Nop hoc phi" << endl;
        cout << "3. In danh sach chua nop hoc phi" << endl;
        cout << "4. Luu danh sach vao file " << endl;
        cout << "5. Thoat (Nhan phim ESC de thoat)" << endl;
        hocVien hvTemp;
        fflush(stdin);
        char chon = _getch();
        switch (chon) {
        case'1': {
            nhapDanhSach(ds);
            //nhapDanhSach(ds);
            break;
        }
        case'2': {
            nopHocPhi(ds);
            break;
        }
        case '3': {
            chuaNop(ds);
            break;
        }
        case '4': {
            save(ds);
            break;
        }
        case 27: {
            cout << "Thoat chuong trinh\n";
            return;
        }
        default: {
            cout << "Lua chon khong hop le!" << endl;
            cin.ignore();
        }
        }

    }
}

int main() {
    hienThiMenu();
    
    return 0;
}