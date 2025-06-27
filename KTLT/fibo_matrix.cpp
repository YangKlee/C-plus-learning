#include <bits/stdc++.h>
using namespace std;
void luythuaMaTran(unsigned long long int  T[][2], long long n)
{
    unsigned long long int T_base[2][2];
    T_base[0][0] = T_base[0][1] = T_base[1][0] = 1ll;
    T_base[1][1] = 0ll;
    unsigned long long int Temp[2][2];
    for (int q = 0; q< n; q++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {   
                long long int sum_tmp = 0;
                for (int k = 0; k < 2; k++)
                {
                    sum_tmp += T[i][k] * T_base[j][k];
                }
                Temp[i][j] = sum_tmp;
            }

        }
        
        T[0][0] = Temp[0][0]; 
        T[0][1] = Temp[0][1]; 
        T[1][0] = Temp[1][0]; 
        T[1][1] = Temp[1][1];

    }
    //return T;
    cout << T[0][0] ;
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long  T[2][2];
    T[0][0] = T[0][1] = T[1][0] = 1ll;
    T[1][1] = 0ll;
    unsigned long long n;
    cin >> n;
     unsigned long long  T_result[2][2];
    //T_result = luythuaMaTran(T,n);
    luythuaMaTran(T,n);
    //cout << T_result[0][1];
    
}