#include "iostream"
using namespace std;
int main()
{
    int x = -1;
    try
    {
        throw x;
        cout << "Hello" << endl;
    }
    catch(int x)
    {
        cout << " Loi" << endl;
    }
    return 0;
}