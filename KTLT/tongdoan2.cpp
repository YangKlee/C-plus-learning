#include <bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        int q;
        cin >> n >> q;
        vector <long long> prefx;
        prefx.resize(n);
        long long sum_tmp = 0;
        for (int i = 0; i < n; i++)
        {
            int x; 
            cin >> x;
            sum_tmp += (long long)x;
            prefx[i] = sum_tmp;
        }
        // query

        for (int i = 0; i < q; i++)
        {
            int left;
            int right;
            cin >> left >> right;
            //cout << right << left << endl;
            //cout << prefx[0] << "-" << prefx[2] << endl ;
            if (left== 0)
                cout << prefx[right] <<endl;
            else
                cout << prefx[right] - prefx[left-1] << endl;
        }
}