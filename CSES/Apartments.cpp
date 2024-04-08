#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector <int> ungvien;
    vector <int> canho;
    int apartment = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ungvien.push_back(tmp);
    }
    sort(ungvien.begin(), ungvien.end());
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        canho.push_back(tmp);
    }
    sort(canho.begin(), canho.end());
    int i = 0;
    int j = 0;
    while(i < ungvien.size() &&j < canho.size())
    {
        if(ungvien[i] > canho[j] && abs(ungvien[i] - canho[j]) >k)
        {
            j++;
        }
        else if(ungvien[i] < canho[j] && abs(ungvien[i] - canho[j]) >k)
        {
            i++;
        }
        else if(abs(ungvien[i] - canho[j]) <=k)
        { 
            apartment++;
            i++;
            j++;
        }
        //cout << i << " "<< j << endl;
    }
    cout << apartment;
}