#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    string s = "I want";
    for(int i = 0; i < n; i++)
    {
        s.push_back('!');
    }
    cout << s ;
}