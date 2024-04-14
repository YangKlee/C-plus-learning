//                _ooOoo_                          NAM MÔ A DI ĐÀ PHẬT !
//               o8888888o
//               88" . "88                
//               (| -_- |)                  
//                O\ = /O
//            ____/`---'\____         Con lạy chín phương trời, con lạy mười phương đất
//            .' \\| |// `.             Chư Phật mười phương, mười phương chư Phật
//           / \\||| : |||// \        Con ơn nhờ Trời đất chổ che, Thánh Thần cứu độ
//         / _||||| -:- |||||- \    Xin nhất tâm kính lễ Hoàng thiên Hậu thổ, Tiên Phật Thánh Thần
//           | | \\\ - /// | |                 Giúp đỡ con code sạch ít bug
//         | \_| ''\---/'' | |               Không TIME LIMIT , không WRONG ANSWER
//         \ .-\__ `-` ___/-. /               AC mọi bài, người người ngưỡng mộ
//       ___`. .' /--.--\ `. . __
//    ."" '< `.___\_<|>_/___.' >'"". NAM MÔ VIÊN THÔNG GIÁO CHỦ ĐẠI TỪ ĐẠI BI TẦM THANH CỨU KHỔ CỨU NẠN
//   | | : `- \`.;`\ _ /`;.`/ - ` : | |  QUẢNG ĐẠI LINH CẢM QUÁN THẾ ÂM BỒ TÁT
//     \ \ `-. \_ __\ /__ _/ .-` / /
//======`-.____`-.___\_____/___.-`____.-'======
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector <int> weight;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        weight.push_back(tmp);
    }
    sort(weight.begin(), weight.end());
    int slot = 0, sum = 0, train = 0;
    int i = 0;
    int j  = weight.size()-1;
    while(i <= j)
    {
        if(weight[i]+ weight[j] <= x)
        {
            train++;
            i++; j--;
        }
        else
        {
            train++;
            j--;
        }
    }
    cout << train;

}