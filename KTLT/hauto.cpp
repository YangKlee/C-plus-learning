#include <bits/stdc++.h>
using namespace std;
string chuyenHauTo(string bt, int l, int r)
{
    stack <char> toantu;
    string ketqua = ""; 
    for (int i = l; i <= r; i++)
    {
        if(bt[i] == '+' || bt[i] == '-' ||bt[i] == '*' ||bt[i] == '/' )
        {
            ketqua = chuyenHauTo(bt, l, i-1);
            toantu.push(bt[i]);
        }
        else
        {
            ketqua = ketqua + bt[i];
        }
    }
    while(toantu.size()> 0)
    {
        ketqua.push_back(toantu.top());
        toantu.pop();
    }
    return ketqua;
}
int main()
{
    cout << chuyenHauTo("12*3+2", 0, 5);
    int n;
    cin >> n;
    stack <char> st;
    string ketqua = ""; 
    string inp ;
    cin >> inp;

}