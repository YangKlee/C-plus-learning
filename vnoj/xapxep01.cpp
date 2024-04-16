#include<bits/stdc++.h>
using namespace std;
vector <int> sort01(vector <int> a)
{
    vector <int>b;
    int count = 0;
    for(int x: a)
    {
        if(x==0)
        {
            b.push_back(0);
            count++;
        }
            
    }
    for(int i = 0; i < a.size()-count; i++)
    {
        b.push_back(1);
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    vector <int> a;
    for(int i = 0; i <n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    a = sort01(a);
    for(int x : a)
        cout << x << ' ';
    
}