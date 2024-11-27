#include <bits/stdc++.h>
using namespace std;
vector <int> x; // chua so nhap vao
vector <int> hv; // chua hoan vi cac anh xa vi tri cua x 
int n;
void show()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[hv[i]] << " ";
    }
    cout << "\n";
}
int fNext()
{
    int pos = -1;
    for (int i = n; i >= 2; i--)
    {
        if (hv[i - 1] < hv[i])
        {
            pos = i - 1;           
            break; 
        }
    }
    return pos;
}
void Next()
{
    show();
    while (1)
    {
        
        int pos = fNext();
        //cout << "POS: " << pos << endl; 
        if (pos == -1)
        {
            return;
        }
        else
        {
            sort(hv.begin() + pos+1, hv.end());
            int posMax = -1;
            for (int i = pos+1; i <= n; i++)
            {
                if (hv[pos] <  hv[i])
                {
                    posMax = i;
                    break;
                }
            }
            int tmp = hv[pos];
            hv[pos] = hv[posMax];
            hv[posMax] = tmp;
            show();
        }
    }
    
}
int main()
{
    cin >> n;
    x.resize(n+1);
    hv.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        hv[i] = i;
    }
    Next();
}