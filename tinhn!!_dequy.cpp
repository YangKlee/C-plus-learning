#include <iostream>
using namespace std;
int giaithua(int n)
{
    if(n == 0)
      return 1;
    else
    {
        return giaithua(n-1) *n;
    }
      
}
int giaithuax2(int n)
{
    if(n <= 0)
      return 1;
    else
    {
      int x = giaithua(n);
       return x * giaithuax2(x - 1);
    }

}

int main()
{
    int n;
    cin >> n;
    //cout << giaithua(giaithua(n)) << endl;
    cout << giaithuax2(n) << endl;
    
}