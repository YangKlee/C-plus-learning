#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int SLBENHNHAN_MAX = 100;
    queue <int> sttBenhNhan;
    int n, STT = 1;
    do
    {
        cout << "Vui long chon \n1. Lay so thu tu \n2. Moi benh nhan \n3. Thoat" << endl;
        cin >> n;
        if (n == 1)
        {
            if (sttBenhNhan.size() < SLBENHNHAN_MAX)
            {
                sttBenhNhan.push(STT);
                cout << "STT ban la: " << STT << endl;
                STT++;
            }
            else
                cout << "cut ve nha! Benh vien qua tai roi~" << endl;
        }
        else if (n == 2)
        {
            if (!sttBenhNhan.empty())
            {    
                cout << "Moi benh nhan so thu tu "  << sttBenhNhan.front() << " vao phong kham" << endl;
                sttBenhNhan.pop();
            }
            else
                cout << "Da het benh nhan~" << endl;
                
        }
        else
            cout << "Lua chon khong hop le" << endl;
            

    } while (n != 3);
    
}