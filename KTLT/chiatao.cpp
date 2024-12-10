#include <bits/stdc++.h>
using namespace std;
vector <long long> w;
long long appleDivide(int i, long long bag1, long long bag2)
{
    if (w.size() == i)
    {
        return abs(bag1 - bag2);
    }
    else
    {
        long long putBag1 = appleDivide(i+ 1, bag1+w[i], bag2 );
        long long putBag2 = appleDivide(i+ 1, bag1, bag2 + w[i]);
        return min(putBag1, putBag2);
    }
}
int main()
{
    int n;
    cin >> n;
    w.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
   
    cout <<  appleDivide(0, 0, 0)<< endl;

}