#include <bits/stdc++.h>
using namespace std;
vector <int> chuyenCoSo(long long int n, int he)
{
    vector <int> result;
    do
    {
        result.push_back(n%he);
        n = n/(long long int)he;
    } while (n != 0);
    return result;
    
}
void inKetQua(vector <int> result)
{
    for (int i = result.size()-1; i >= 0; i--)
    {
        
        if (result[i] >= 10)
        {
            char c = 'A';
            cout << (char)(c + (result[i] - 10));
        }
        else
            cout << result[i] ;

    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin >> n;
    vector <int> result;
    result = chuyenCoSo(n,2);
    inKetQua(result);
    result.clear();
    result = chuyenCoSo(n,8);
    inKetQua(result);
    result.clear();
    result = chuyenCoSo(n,16);
    inKetQua(result);
}