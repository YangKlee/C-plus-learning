#include<bits/stdc++.h>
using namespace std;
bool plies(int a, int b)
{
    if((2*a-b)%3 == 0 && (2*a-b) >= 0 &&(2*b-a)%3 == 0 && (2*b-a) >= 0 )
        return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
            if(plies(a,b))
                cout << "YES" << endl;
            else
                cout << "NO"<< endl;
    }
    
}