#include <bits\stdc++.h>
using namespace std;
int main()
{
    vector <int> a;
    char arg;
    int n;
    cin >> n;
    bool isShow = false;
    for (int i = 0; i < n; i++)
    {
        cin >> arg;
        if (arg == 'a'){
            int x;
            cin >> x;
            a.push_back(x);
        }
        else if(arg == 'b')
        {
            sort(a.begin(), a.end());
        }
        else if(arg == 'c')
        {
            reverse(a.begin(), a.end());
        }
        else if(arg == 'd')
        {
            isShow = true;
            cout << a.size() << " ";
        }
        else if(arg = 'e')
        {
            isShow = true;
            for (int x:a)
            {
                cout << x << " ";
            }
        }
        else if(arg = 'f')
        {
            sort(a.begin(), a.end(), greater<>());
        }
    }
    if(!isShow)
    {
        cout << "-1" << endl;
    }


}