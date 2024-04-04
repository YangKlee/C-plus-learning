#include <bits/stdc++.h>
using namespace std;
void read_file(long long &n)
{
    ifstream input;
    input.open("hecoso.inp");
    input >> n;
    input.close();

}
void write_file(int x)
{
    ofstream output;
    output.open("hecoso.out");
    output << x;
    output.close();
}
long long doinhiphan(long long n)
{
    if(n == 0)
        return 0;
    else
    {
        return (1LL* n%2 * 10) +doinhiphan(n/2LL);
    }
}
int main()
{
    long long n;
    cin >> n;
    cout << doinhiphan(n);
    
}