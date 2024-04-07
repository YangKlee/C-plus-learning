#include <bits\stdc++.h>
using namespace std;
set<int> Eratosthenes(int a, int b, int k, set <int> no_prime)
{
    int i = 0;
    //cout << k << endl;
    if(k*k > b)
    {
        return no_prime;
    }
    while (k*(k+i) <= b)
    {
        no_prime.insert(k*(k+i));
        i++;
    }
    for(int i = k+1; i <= b; i++)
    {
        
        if(no_prime.find(i) == no_prime.end())
        {
            k = i;
            break;
        }
    }
    return Eratosthenes(a,b,k, no_prime);
    //return no_prime;  
}

int main()
{
    int a,b;
    set <int> no_prime;
    cin >> a >> b;
    no_prime = Eratosthenes(a,b,2,no_prime);
    

    /*
    for(int i = a+1; i <= b; i++)
    {
        if(no_prime.find(i) == no_prime.end())
        {
            cout << i << ' ';
        }

    }
    */

}