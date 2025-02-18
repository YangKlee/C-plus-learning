#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4] = {1, 2, 3 , 4};
    int *arr_p = &arr[0];
    while (arr_p <= &arr[3])
    {
        cout << *arr_p << " ";
        arr_p++;
    }
}