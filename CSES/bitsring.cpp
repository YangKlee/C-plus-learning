#include<bits/stdc++.h>
using namespace std;
void createBits(int k, int n, int bits[])
{
    for(int i = 0; i <= 1; i++)
    {
        bits[k] = i;
        if(k == n)
        {
            for(int i = 1; i <=n ; i++)
            {
                cout << bits[i] ;
            }
            cout << '\n';
        }
        else
        {
            createBits(k+1, n, bits);
        }
    }
}
int main()
{
    int n, bits[100];
    cin >> n;
    createBits(1,n, bits);

}