#include <bits\stdc++.h>
using namespace std;
// vi du su khac nhau giua nhap chuoi dung cin voi getline
void ViDu1()// vi du dung cin
{

    string Name;
    int MSV;
    cout << "Nhap MSV cua ban: " << endl; cin >> MSV;
    cout << "Nhap ho ten cua ban: " << endl; cin >> Name;
    cout << "Ma sinh vien: " << MSV << "\nHoTen: "<< Name << endl;
    // String chi nhan duoc mot tu - khong nhan khoang cach

}
void ViDu2()// vi du dung getline
{

    string Name;
    int MSV;
    cout << "Nhap MSV cua ban: " << endl; cin >> MSV;
    cin.ignore(); // xoa bo dem ban phim
    cout << "Nhap ho ten cua ban: " << endl; getline(cin,Name);
    cout << "Ma sinh vien: " << MSV << "\nHoTen: "<< Name << endl;
    // String nhan duoc dau cach , nhung nhan luon ca bo dem ban phim
    
}
int main()
{
    ViDu2();
}