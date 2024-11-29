#include <bits/stdc++.h>
using namespace std;
struct Diem
{
    float x,y;
    Diem(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};
void inputFile(vector <Diem> &dsDiem)
{
    int n;
    float a, b;
    freopen("point_list.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        dsDiem.push_back(Diem(a,b));
    }
}
float BinhPhuong(float x)
{
    return x*x;
}
float tinhKhoangCach(Diem A, Diem B)
{
    return sqrt(BinhPhuong(A.x - B.x) + BinhPhuong(A.y - B.y));
}
pair<Diem, Diem> timDiemXaNhau(vector <Diem> dsDiem)
{
    pair<Diem, Diem> ketQua = make_pair(Diem(0,0), Diem(0,0));
    float max = 0;
    for (int i = 0; i < dsDiem.size(); i++)
    {
        for (int j = i+1; j < dsDiem.size(); j++)
        {
            float diff = tinhKhoangCach(dsDiem[i], dsDiem[j]);
            if (diff > max)
            {
                ketQua = make_pair(dsDiem[i], dsDiem[j]);
                max = diff;
            }
        }
    }
    return ketQua;
}
void showPoint(vector <Diem> dsDiem)
{
    for (int i = 0; i < dsDiem.size(); i++)
    {
        cout << dsDiem[i].x << " " << dsDiem[i].y << endl;
    }
}
int main()
{
    vector <Diem> dsDiem;
    inputFile(dsDiem);
    cout << "Thong tin cac diem" << endl;
    showPoint(dsDiem);
    pair <Diem, Diem> haiDiemXaNhau = timDiemXaNhau(dsDiem);
    cout << "Hai diem xa nhau nhat" << endl;
    cout << haiDiemXaNhau.first.x << " " << haiDiemXaNhau.first.y << endl;
    cout << haiDiemXaNhau.second.x << " " << haiDiemXaNhau.second.y << endl;
}