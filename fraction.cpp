#include "iostream"
#include "fstream"
#include "math.h"
using namespace std;
struct fraction
{
    int x; // aka tu
    int y; // aka mau
};
int detect_ngto(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int type_fraction(int mau)
{
    for (int i = 2; i < mau; ++i)
    {
        if(i != 5 && i !=2 && detect_ngto(i) == 1)
        {
            if(mau % i == 0)
                return 0;
        }
    }
    return 1;
}
void write_file(int fraction_type_list[], int n)
{
    ofstream output;
    output.open("fraction.out");
    for(int i = 0; i < n; i++)
    {
        if(fraction_type_list[i] == 1)
            output << "finite\n";
        else if (fraction_type_list[i] == 0)
            output << "repeating\n";
    }
    output.close();
}
void read_file(fraction frac)
{
    int n;


    // get number of elements
    ifstream input;
    input.open("fraction.inp");
    input >> n;
    int fraction_type_list[n];
    for(int i = 0; i < n; i++)
    {
        frac.x = 1;
        frac.y = 1;
        int k;
        // get number of elements of fractions
        input >> k;

        for(int j = 1 ; j <= k*2; j++ )
        {
            int temp;
            input >> temp;
            if(j > k)
            {
                frac.y *= temp;

            }
        }
        //cout << frac.y << endl;
        //cout << type_fraction(frac.y) << endl;
        fraction_type_list[i] = type_fraction(frac.y);
    }
    input.close();
    write_file(fraction_type_list, n);
}

int main()
{
    struct fraction frac;
    read_file(frac);
}
