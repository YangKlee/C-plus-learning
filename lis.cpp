#include<bits/stdc++.h>
using namespace std;
void TruyVet(vector <int> a,vector <int> &after, vector <int> &L)
{
    int max = 0, max_index = 0;
    for(int i = 0; i < L.size(); i++)
    {
        if(L[i] > max)
        {
            max = L[i];
            max_index = i;
        }
        while(i >= 0)
        {
            cout << a[i+1];
            i = after[i-1];
        }
    }
}
void LIS(vector <int> a,vector <int> &after, vector <int> &L)
{
    int curr = 0;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i] )
            {
                L[i] = max(L[i], L[j]+1); 
                //L[i] = L[j]+1;
                after[i] = i;
            }
            
        }
    }
}
void Debug(vector <int> a)
{
    for(int x:a)
    {
        cout << x << ' ';

    }
    cout << '\n';
}
int main()
{
    int n;
    cin >> n;
    vector <int> a;
    vector <int> L(n,1);
    vector <int> After(n, 0);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    LIS(a,After,L);
    int N_LIS = *max_element(L.begin(), L.end());
    Debug(After);
    cout <<"So phan tu: "<< N_LIS << endl;
    //TruyVet(a,After,L);

}