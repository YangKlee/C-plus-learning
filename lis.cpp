#include<bits/stdc++.h>
using namespace std;
void GetLIS(vector <int> a,vector <int> after, int N_LIS)
{
    // tim vi tri so lon nhat
    vector <int> result;
    int max_after = 0;
    int max_pos_after = 0;
    for(int i = 0; i < after.size(); i++)
    {
        if(after[i] > max_after)
        {
            max_after = after[i];
            max_pos_after = i;
        }
    }
    result.push_back(a[max_pos_after]);
    // muc tieu la tim so co khoang cach nho nhat voi max
    while(N_LIS > 0)
    {
        int diff_min = INFINITY;
        int diff_min_pos = -1;
        for(int i = 0; i < max_pos_after; i++)
        {
            if(abs(after[i] - max_after) < diff_min)
            {
                diff_min = abs(after[i] - max_after);
                diff_min_pos = i;
            }

        }
        max_after = after[diff_min_pos];
        
        max_pos_after = diff_min_pos;
        if(diff_min_pos != -1)
            result.push_back(a[diff_min_pos]);
        N_LIS--;
    }
    for(int i = result.size()-1; i >= 0; i--)
    {
        cout << result[i] << ' ';
    }

}
void LIS(vector <int> a,vector <int> &after, vector <int> &L)
{
    int curr = 0;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                L[i] = max(L[i], L[j]+1); 
                curr = j+1;
            }
            else
            {
                curr = 0;
            }
            after[i] = curr;

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
    GetLIS(a,After,N_LIS);

}