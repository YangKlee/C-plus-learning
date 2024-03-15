#include "iostream"
using namespace std;

int dem_chu_so(int n)
{
    if(n == 0)
        return 0;
    else
        return 1+ dem_chu_so(n/10);
}
int main()
{
    int n;
    cin >> n;
    cout << dem_chu_so(n) << endl;
}