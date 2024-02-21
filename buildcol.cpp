#include "iostream"
#include "math.h"
#include "fstream"
using namespace std;
void read_file(int a[], int &n, int &m)
{
    ifstream input;
    input.open("buildcol.inp");
    input >> n;
    input >> m;
    for (int i = 0; i < n; ++i) {
        input >> a[i];
        //cout << a[i];
    }
    input.close();

}
void write_file(int x)
{
    ofstream output;
    output.open("buildcol.out");
    output << x;
    output.close();
}
void xuatmang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i]<< endl;
	}
	cout << "\n";
}
void tinhDNV(int col[], int water[], int n)
{
    // do tim ben trai -> phai
    int privot = 0;
    int temp = col[0];
    for(int i = 0; i < n ; i++)
    {
        if(col[i] <= temp)
        {
            if(temp - col[i] > 0)
            {
                   water[i] = temp - col[i];
            }
            else
                water[i] = 0;
        }
        else
        {
            temp = col[i];
            privot = i;
            water[i] = 0;
        }
    }
    if(privot != n-1)
    {
        temp = col[n];
        for(int i = n; i >= privot-1 ; i--)
        {

            if(col[i] <= temp)
            {
                if(temp - col[i] > 0)
                {
                   water[i] = temp - col[i];

                }
                else
                    water[i] = 0;
                //cout <<"DEBUG: "<<i << " "<< col[i] << endl;
            }
            else
            {
                temp = col[i];
                privot = i;
                water[i] = 0;
            }
        }

    }


}
int get_dvn(int water[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum+=water[i];
    }
    return sum;
}
int get_min_build(int col[], int n)
{
    int min = col[0];
    for(int i = 0; i < n; i++)
    {
        if(col[i] < min)
            min = col[i];
    }
    return min;
}
void calc_Max_Water(int col[], int water[], int n, int m)
{
    int x = 0;
    tinhDNV(col, water, n);
    //cout << get_dvn(water, n) << endl;
      //xuatmang(water, n);
    while(get_dvn(water, n) >= m)
    {
        for(int i = 1 ; i < n-1; i++)
        {
            if(water[i] > 0)
                water[i]--;
        }
        //xuatmang(water, n);
        x++;
    }
    write_file(x+ get_min_build(col, n));


}
int main()
{
    int n, m;
    // get num
    ifstream input;
    input.open("buildcol.inp");
    input >> n;
    input.close();
    int col_data[n], water_data[n];
    read_file(col_data, n, m);
    //xuatmang(col_data, n);
    calc_Max_Water(col_data, water_data, n, m);
    //xuatmang(col_data, n);

}
