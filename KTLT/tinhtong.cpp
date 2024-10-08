#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    long long result = 0;
    for (int i = 0; i <n; i++)
    {
        long long tmp;
        cin >> tmp;
        result += tmp;

    }
    cout << result;
}