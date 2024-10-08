#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> duong;
    vector <int> am;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp >= 0)
            duong.push_back(tmp);
        else
            am.push_back(tmp);
    }
    int i = 0, j = 0;
    while(i < duong.size() && j < am.size())
    {
        cout << duong[i] << " " << am[j] << " ";
        i++; j++;
    }
    while (i < duong.size())
    {
        cout << duong[i] << " ";
        i++;
    }
    while (j < am.size())
    {
        cout << am[j] << " ";
        j++;
    }
}