#include "iostream"
using namespace std;
void draw_Pyramid(int n)
{
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
}
int main()
{
    draw_Pyramid(5);
}