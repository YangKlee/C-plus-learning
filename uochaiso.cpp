#include "iostream"
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;

    int n, uoc = 1;
    (a<b)? n = a: n = b;

    for (int i = 1; i <= n; ++i) {
        if(a%i == 0 && b%i == 0)
        {
            cout << i << endl;
        }

    }

}

