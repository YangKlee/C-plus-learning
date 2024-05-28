#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tmp;
    vector <int> a;
    while(cin >> tmp)
    {
        a.push_back(tmp);
    }
    int count = 0;
    for(int i =0 ; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] > a[j] && i < j )
            {
                count++;
            }
        }
    }
    cout << count;
}