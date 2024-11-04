#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        int q;
        cin >> n >> q;
        vector <int> prefx;
        prefx.resize(n);
        int sum_tmp = 0;
        for (int i = 0; i < n; i++)
        {
            int x; 
            cin >> x;
            sum_tmp += x;
            prefx[i] = sum_tmp;
        }
        // query

        for (int i = 0; i < q; i++)
        {
            int left;
            int right;
            cin >> left;
            cin >> right;
            cout << right << left << endl;
            //cout << prefx[0] << "-" << prefx[2] << endl ;
            if (left == 0)
                cout << prefx[right] << endl;
            else
                cout << prefx[right] - prefx[left-1] << endl;
        }
}