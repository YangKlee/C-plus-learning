#include "iostream"

using namespace std;
int songuoc(int n)
{
    if(n == 0)
        return 0;
    else
        return  n%10 + songuoc(n/10);

}
int main()

{
    int n = 7;
    cout << songuoc(n);
}