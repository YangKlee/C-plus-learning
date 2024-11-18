#include <bits/stdc++.h>
using namespace std;
string bin = "";
void inilazie(int n)
{
    for (int i = 0; i < n; i++)
    {
        bin = bin + "0";
    }
    return;
}
void show()
{
    cout << bin << endl;
}
bool next(int n)
{
    for (int i = bin.length() - 1; i >= 0; i--)
    {
        if (bin[i] == '0')
        {
            bin[i] = '1';
            for (int j = i + 1; j < bin.length(); j++)
            {
                bin[j] = '0';
            }
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    inilazie(n);
    show();
    while (next(n))
    {
        show();
    }
}