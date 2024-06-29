#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> prefix(n);
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    // khoi tao mang prefix 
    prefix[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i-1]+ a[i];
    }

    // truy vet day con
    int max_left = 0;
    int max_right = 0;
    int sum_max = 0;
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(prefix[i] - prefix[j] > sum_max)
            {
                max_left = j;
                max_right = i;
                sum_max = prefix[i] - prefix[j];
            }
        }
    }
    
    // hien thi ket qua
    for(int i = max_left+1; i <= max_right; i++)
    {
        cout << a[i] << ' ';
    }
    

}