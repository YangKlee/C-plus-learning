
#include <iostream>
using namespace std;
int calc_n_k(int n, int k)
{
    if(k == n || k == 0)
        return 1;
    else
        return calc_n_k(n - 1, k) + calc_n_k(n - 1, k - 1);
}

int main()
{
    int n, k;
    cout << "Nhap n va k: ";
    cin >> n >> k;
    cout << "Ket qua la: " << calc_n_k(n,k) << endl;

}