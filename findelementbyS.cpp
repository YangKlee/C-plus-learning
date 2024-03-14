
#include <iostream>
#include <math.h>
using namespace std;
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}

int find_equas_is_S(int a[],int n, int s)
{
    int sum = 0, x;
    //cout << "s = "<<s << endl;
    if(s <= 0 )
    {
        return 1;
    }
    else
    {   
        for (int i = 0; i < n; i++)
        {
            x = s - a[i];
            for(int j = 0; j < n; j++)
            {
                if(x == a[j] && x + sum <= s)
                {
                    if(a[j] != 0)
                        cout << x << " ";
                    sum += x;
                    a[j] = 0;
                }
            }

        }
        if(sum != 0)
            return find_equas_is_S(a,n, s - sum);
        else
        {
            for (int i = 0; i < n; ++i) {
                if(find_equas_is_S(a,n, s - a[i])!= 1)
                {
                    break;
                }
            }
        }
    }

}
int main()
{
    int n, s;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[100];
    cout << "Nhap cac phan tu cua mang: ";
    inputArray(a,n);
    cout << "Nhap S: ";
    cin >> s;
    find_equas_is_S(a,n,s);
    

}