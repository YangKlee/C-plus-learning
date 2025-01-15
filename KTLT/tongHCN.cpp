#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vti vector <int>
#define vtll vector <long long>
#define vtf vector <float>
#define str string
#define el cout << "\n"
using namespace std;
int main()
{
    IOS;
    int m,n,k;
    cin >> n >> m >> k;
    vector <vti> prefix(n);
    // i dòng , j cột
    for (int i = 0; i < n; i++)
    {
        prefix[i].resize(m,0);
        for (int j = 0; j < m; j++)
        {
            int tmp; cin >> tmp;
            if (i == 0 && j == 0)
            {
                prefix[i][j] = tmp;
            }
            else if (i == 0)
            {
                prefix[i][j] = prefix[i][j-1] + tmp;
            }
            else if (j == 0)
            {
                prefix[i][j] = prefix[i-1][j] + tmp;
            }
            else
            {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + tmp;
            }
        }
    }
    // query
    for (int i = 0; i < k; i++)
    {
        int x1, x2,y1,y2;
        cin >> x1 >> x2>> y1>> y2;
        if ((x1 == 0 && x2 == 0))
        {
            cout << prefix[y1][y2] << endl;
        }
        else if (x2 == 0 && x1 != 0)
        {
            cout << prefix[y1][y2] - prefix[x1-1][y2]<< endl;
        }
        else if (x1 == 0 && x2 != 0)
        {
            cout << prefix[y1][y2] - prefix[y1][x2 -1]<< endl;
        }
        else
        {
            cout << prefix[y1][y2] - prefix[y1][x2 - 1] - prefix[x1-1][y2] + prefix[x1-1][x2-1] << endl;
        }
    }
}