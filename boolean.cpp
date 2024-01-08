#include "iostream"
using namespace std;
int main() {
    bool a = false;
    cout << a << endl;
    cout << !a << endl;
    cout << std::boolalpha;
    cout << a << endl;
    cout << !a << endl;
    cout << std::noboolalpha;
    cout << a << endl;
    cout << !a << endl;
    if(a)
    {
        cout << "iu em \n";
    }
    else
    {
        cout << "hong iu em\n";
    }

}
