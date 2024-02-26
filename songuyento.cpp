#include "iostream"
#include "math.h"
using namespace std;
bool check_Prime(int a)
{
    for (int i = 2; i <= sqrt(a); ++i) {
        if(a % i == 0)
            return false;
    }
    return true;
}
int count_prime(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if(check_Prime(a[i]))
            count++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    count_prime()

}