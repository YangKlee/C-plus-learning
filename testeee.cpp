#include <iostream>

int main() {
    // Khai báo hai số
    int num1 = 8, num2 = 6;

    // Tìm số nhỏ hơn trong hai số
    int smaller = (num1 < num2) ? num1 : num2;

    // Liệt kê tất cả các ước
    std::cout << "Cac uoc cua " << num1 << " va " << num2 << " la: ";
    for (int i = 1; i <= smaller; ++i) {
        if (num1 % i == 0 && num2 % i == 0) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
