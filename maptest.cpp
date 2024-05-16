#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <int, int> mp;
    mp[100] = 150;
    mp[200] = 250;
    mp.insert({300,350});
    cout << mp.size();
    for(map <int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
}