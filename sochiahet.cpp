#include "iostream"
using namespace std;

int find_chia_het(int a, int b)
{
    if(a % b == 0)
        return a;
    else
        return find_chia_het(a-1, b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    //cout << find_chia_het(a,b);
    cout <<
}