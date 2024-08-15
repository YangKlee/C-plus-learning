#include <bits\stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    IOS;
    int w;
    cin >> w;
    if(w%2 == 0 && w >2)
        cout << "YES";
    else
        cout << "NO";
}