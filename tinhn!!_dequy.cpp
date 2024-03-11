#include <iostream>
using namespace std;
int giaithua(int n)
{
    if(n == 0 || n == 1)
      return 1;
    else
    {

      return giaithua(n-2) *n;

    }
      
}


int main()
{
    int n;
    cin >> n;
    //cout << giaithua(giaithua(n)) << endl;
    cout << giaithua(n) << endl;
    
}