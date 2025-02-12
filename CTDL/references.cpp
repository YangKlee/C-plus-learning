#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 10;
    int *a_p = &a;
    int **b_p = &a_p;
    **b_p = 1;
    cout << a;
}