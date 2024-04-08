#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, temp;
    string duoi = ".py";
    getline(cin,s);
    for(char &x : s) 
		x = tolower(x);
    int vitri = s.find_last_of('.');
    for(int i = vitri; i < s.length(); i++)
    {
        temp.push_back(s[i]);
    }
    if(duoi == temp)
    {
        cout << "yes";
    }
    else
        cout << "no";
}