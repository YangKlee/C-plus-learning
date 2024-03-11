
#include <iostream>
#include <math.h>
using namespace std;
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
//                _ooOoo_                          NAM MÔ A DI ĐÀ PHẬT !
//               o8888888o
//               88" . "88                Thí chủ con tên là Nguyễn Khánh Dương, sinh 18/07/2005
//               (| -_- |)                    Ngụ tại Bùi Thị Xuân, Quy Nhơn, Bình Định
//                O\ = /O
//            ____/`---'\____         Con lạy chín phương trời, con lạy mười phương đất
//            .' \\| |// `.             Chư Phật mười phương, mười phương chư Phật
//           / \\||| : |||// \        Con ơn nhờ Trời đất chổ che, Thánh Thần cứu độ
//         / _||||| -:- |||||- \    Xin nhất tâm kính lễ Hoàng thiên Hậu thổ, Tiên Phật Thánh Thần
//           | | \\\ - /// | |                 Giúp đỡ con code sạch ít bug
//         | \_| ''\---/'' | |               Chạy không crash, execute vèo vèo
//         \ .-\__ `-` ___/-. /          Thông thạo đệ quy, người người ngưỡng mộ
//       ___`. .' /--.--\ `. . __
//    ."" '< `.___\_<|>_/___.' >'"". NAM MÔ VIÊN THÔNG GIÁO CHỦ ĐẠI TỪ ĐẠI BI TẦM THANH CỨU KHỔ CỨU NẠN
//   | | : `- \`.;`\ _ /`;.`/ - ` : | |  QUẢNG ĐẠI LINH CẢM QUÁN THẾ ÂM BỒ TÁT
//     \ \ `-. \_ __\ /__ _/ .-` / /
//======`-.____`-.___\_____/___.-`____.-'======
int find_equas_is_S(int a[], int n, int s)
{
    int x, dem = 0;
    if(s <= 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        x = s - a[i];
        for(int j = 0; j < n; j++)
        {
            if(x == a[j])
            {
                cout << a[j] << " ";
                dem++;
                break;
            }

        }
        if(dem == 0)
        {
            cout << endl;
            return find_equas_is_S(a,n, x) ;
        }
        else
        {
            dem = 0;
        }

    }

}
int main()
{
    int n, s;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    inputArray(a,n);
    cout << "Nhap S: ";
    cin >> s;
    find_equas_is_S(a,n,s);

}