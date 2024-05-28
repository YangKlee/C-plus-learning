#include<bits/stdc++.h>
using namespace std;
void inmang(int a[2][2]);
void luythua(int a[2][2], int n)
{
    for (int i = 0; i < 2; i++)
    {
        int tmp[2][2] = {{0,0}, {0,0}};
        for (int j = 0; j < 2; j++)
        {
            int sum = 0;
            for(int k = 0; k < 2; k++)
            {
                sum += a[k][i] * a[j][k];
            }
            tmp[i][j] = sum;
        }
        inmang(tmp);
        a = tmp;
    }
    
}
void inmang(int a[2][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2  ; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    int a[2][2] = {{0,1}, {1,1}};
    int base[2][2] = {{0,0}, {0,0}};
    int v[2] = {0,1};
    int n;
    cin >> n;
    luythua(a,n);
    inmang(a);
}