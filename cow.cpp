#include "iostream"
#include "fstream"
using namespace std;
void read_file(int &n, int &s)
{
    ifstream input;
    input.open("cows.inp");
    input >> n;
    input >> s;
    input.close();
}
void write_file(int x)
{
    ofstream output;
    output.open("cows.out");
    output << x;
    output.close();
}
int main()
{
    int n, s, sum = 0;
    read_file(n,s);
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    write_file(sum - s);
}
