#include<bits/stdc++.h>
using namespace std;
string fractionShorten(int a, int b)
{
    int min;
    (a>b)? min = b:min = a;
    int k;
    for(int i = min; i >= 2; i--)
    {
        if(a%i == 0 && b%i == 0)
            k = i;
    }
    a /= k;
    b /= k;
    std::string tu = std::to_string(a);
    std::string mau = std::to_string(b);
    return tu +"/"+ mau;
}
int main()
{
    
}