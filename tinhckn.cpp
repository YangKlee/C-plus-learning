#include<bits/stdc++.h>
using namespace std;
/*
void Debug(int C[100][100], int n, int k)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            cout << C[i][j]<< ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
*/
int main()
{
    int n,  k;
    cin >> n >> k;
    int C[400][400];
    // khoi tao
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j == 0)
                C[i][j] = 1;
            else if(i == j)
                C[i][j] = 1;

        }
    }
    //Debug(C,n,k)  ;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
        //Debug(C,n,k)  ;
    }
    cout << C[n][k];

}
