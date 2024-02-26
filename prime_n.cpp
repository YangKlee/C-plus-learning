#include "iostream"
#include "math.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 2 ; i--) {

        int count = 0;
        for (int j = 2; j <= sqrt(i) ; ++j) {
            if(i % j == 0)
                count ++;
        }
        if(count == 0)
        {
            cout << i;
            break;
        }


    }
}