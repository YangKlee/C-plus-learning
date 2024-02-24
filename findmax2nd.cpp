#include "iostream"
using namespace std;
int main()
{
    int a = 18, b = 9, c = 6;
    int sec_max;
    if(a > b && a > c)
    {
        if(b > c)
            sec_max = b;
        else
            sec_max = c;
    }
    else if(b > a && b > c)
    {
        if(a > c)
            sec_max = a;
        else
            sec_max = c;

    }
    else
    {
        if(b > c)
            sec_max = b;
        else
            sec_max = c;
    }
    cout << sec_max;

}