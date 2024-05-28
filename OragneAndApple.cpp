#include <bits/stdc++.h>
using namespace std;
void calc_house(int s, int t, int a, int b, vector <int> apples, vector <int>organes)
{
    int count = 0;
    for(int tao : apples)
    {
        if(tao + a >= s && tao + a <= t)
            count++;
    }
    cout << count << endl;
    count = 0;
    for(int cam : organes)
    {
        if(cam + b >= s && cam + b <= t)
            count++;
    }
    cout << count << endl;
}
int main()
{
    int s,t,a,b,m,n;
    vector <int> apples;
    vector <int> orgages;
    cin >> s >> t >> a >> b >> m >> n;
    for(int i = 0; i < m; i++)
    {
        int tmp; cin >> tmp;
        apples.push_back(tmp);
    }
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        orgages.push_back(tmp);
    }
    calc_house(s,t,a,b,apples, orgages);


}
