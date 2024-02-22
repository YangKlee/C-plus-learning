// thư viện nhập xuất trong c++, mọi chương trình cần nhập xuất đều phải import thư viện này
#include "iostream"
// khai báo using namespace std để tiện cho sử dụng sau này, nếu không khai báo cũng đc nhưng ...
//..cần phải thêm tiền tố std:: trước câu lệnh nhập xuất
using namespace std;
/*
 * Đôi chút về hàm main
 * - Hàm main là hàm ĐẦU TIÊN mà chương trình chạy vào
 * - Trong một chương trình C++, chỉ được phép có DUY NHẤT một hàm main
 * */
int main()
{
    // in ra màn hình
    // endl giúp tự động đưa con trỏ xuống dòng khi in xong, giúp lần in tiếp theo sẽ ở dòng dưới
    cout << "Nahida and Klee so cute" << endl;
    // example - so sanh giua co endl va khong co endl
    cout << "Klee";
    cout << "Nahida";
    cout << "\n";
    cout << "Klee" << endl;
    cout << "Nahida" << endl;

    // có thể thay endl thành "\n"
    cout << "Klee" << "\n";
    cout << "Nahida" << "\n";

    // ta có thể in nhiều phần tử ra màn hình cùng lúc bằng cách thêm <<
    cout << 1 << "+" << 1 <<"="<< 2 << endl;

    // câu lệnh này sẽ trả về giá trị cho complier khi biên dịch thành công
    // mặc định giá trị là 0
    // return không bắc buộc ở hàm main, có hay không cũng đc

    return 0;
}