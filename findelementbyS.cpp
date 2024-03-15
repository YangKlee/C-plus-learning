
#include <iostream>
#include <math.h>
using namespace std;
//bool allow_recuition = true, int index;
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}
void exportArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    
}
void xapxep_arr(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int min;
            if(a[i] > a[j])
            {
                min = a[j];
				a[j] = a[i];
				a[i] = min;
            }
        }
        
    }
}
int sumArray(int a[], int n)
{
    int sum  = 0;
    for(int i = 0; i < n; i++)
    {
        sum+= a[i];
    }
    return sum;
}
int find_equas_is_S(int a[], int b[],int n, int k /*for b*/ , int s)
{
    int sum = sumArray(b,k+1);
    if(sum == s)
    {
        exportArray(b,k+1);
        return 0;
    }
    else
    {
        b[k] = a[n-1];
        //cout << "bk" << b[k] << endl;
        //cout << "sumb" << sumArray(b,k+1) << endl;
        if(sumArray(b,k+1) >= s)
            return find_equas_is_S(a,b,n-1, k,s);
        return find_equas_is_S(a, b, n-1,k+1,s);
    }

}

int main()
{
    int n, s;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[100], b[100];
    cout << "Nhap cac phan tu cua mang: ";
    inputArray(a,n);
    cout << "Nhap S: ";
    cin >> s;
    xapxep_arr(a,n);
    find_equas_is_S(a,b,n,0,s);
    

}