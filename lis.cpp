#include<bits/stdc++.h>
using namespace std;
void LIS(vector <int> a, vector <int> &L)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                L[i] = max(L[i], L[j]+1);    
            }

        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector <int> a;
    vector <int> L(n,1);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    LIS(a,L);
    cout <<"So phan tu: "<< *max_element(L.begin(), L.end()) << endl;

}