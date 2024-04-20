#include<bits/stdc++.h>
using namespace std;
int main()
{
    set <int> a;
    a.insert(1);
    a.insert(2);
    a.insert(2);
    a.insert(2);
    a.insert(3);
    a.insert(3);
    //sort(a.begin(), a.end(), greater());
    for(auto x:a)
    {
        cout << x<< ' ';
    }
}