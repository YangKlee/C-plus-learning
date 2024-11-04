#include<bits/stdc++.h>
using namespace std;
int tinhHauTo(string bieuThuc)
{
    stack <int> result;
    for (int i = 0; i < bieuThuc.length(); i++)
    {
        if (bieuThuc[i] >= '0' && bieuThuc[i] <= '9')
        {
            result.push(int(bieuThuc[i] - '0'));
        }
        else
        {
            int b = result.top(); result.pop();
            int a = result.top()a; result.pop();
            if (bieuThuc[i] == '+')
                result.push(a+b);
            else if(bieuThuc[i] == '-')
                result.push(a-b);
            else if(bieuThuc[i] == '*')
                result.push(a*b);
            else if(bieuThuc[i] == '/')
            {
                if(b == 0)
                    result.push(0);
                else
                    result.push(a/b);
            }
        }
    }
    return result.top();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    string bieuThuc;
    for (int i = 0; i < n; i++)
    {
        getline(cin, bieuThuc);
        cout << tinhHauTo(bieuThuc) << endl;
    }
}