#include <bits/stdc++.h>
using namespace std;
void show(vector <float> h, vector <float> kq)
{
    for (int i = 0; i < h.size(); i++)
    {
        cout << h[i] << " "<< kq[i] << endl;
    }
}
vector <float> thuatToanA(vector <float> h, vector <float> s)
{
    vector <float> kq(s.size());
    vector <bool> isUse(h.size(), 0);
    //sort(h.begin(), h.end());
    //sort(s.begin(), s.end());
    for (int i = 0; i < h.size(); i++)
    {
        float min = INFINITY;
        int tmp = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (fabs(h[i] - s[j]) < min && isUse[j] == 0)
            {
                tmp = j;
                min = fabs(h[i] - s[j]);
                //kq[i] = s[j];
            }
        }
        isUse[tmp] = 1;
        kq[i] = s[tmp];
    }
    return kq;
}
vector <float> thuatToanB(vector <float> &h, vector <float> s)
{
    sort(h.begin(), h.end(), greater());
    sort(s.begin(), s.end(), greater());
    vector <float> kq(s.size());
    vector <bool> isUse(h.size(), 0);
    for (int i = 0; i < s.size(); i++)
    {
        kq[i] = s[i];
    }
    return kq;
}
int main()
{
    int n;
    cin >> n;
    vector <float> h(n);
    vector <float> s(n);
    cout << "Nhap chieu cao nguoi: ";
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    cout << "Nhap size giay: ";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cout << "Ket qua thuat toan A" << endl;
    show(h, thuatToanA(h,s));
    cout << "Ket qua thuat toan B" << endl;
    show(h, thuatToanB(h,s));
}