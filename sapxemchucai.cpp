#include<bits/stdc++.h>
using namespace std;
string Xapxepchucai(string a)
{
    string b;
    for(char i = 'z'; i >= 'a'; i--)
    {
        for(int j = 0; j < a.length(); j++)
        {
            if(a[j] == i)
            {
                b.push_back(i);
            }
        }
    }   
    return b;
}

int main()
{
    string a;
    cin >> a;
    a = Xapxepchucai(a);
    cout << a;

}