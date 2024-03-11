#include <iostream>
using namespace std;
bool checkSauCon(string s1, string s2, int n, int m)
{
    if(n == 0)
        return 1;
    else if(m == 0)
        return 0;
    else
    {
        // debug code
        //cout <<s1[n-1]<< "-"<<s2[m-1]<< endl;
        //cout <<n-1<< "-"<<m-1<< endl;
        if(s1[n-1] == s2[m-1])
        {
            return checkSauCon(s1,s2,n - 1,m-1);
        }
        else
        {
            return checkSauCon(s1, s2, s1.length(), m - 1);
        }
    }
}
int main()
{
    string s1, s2;
    cout << "Nhap sau s1: "; 
    getline(cin, s1);
    //cin >> s1;
    cout << "Nhap sau s2: ";
    getline(cin, s2);
    //cin >> s2;

    if(checkSauCon(s1,s2,s1.length(), s2.length()))
        cout << "S1 la sau con cua S2" << endl;
    else
        cout << "S1 khong phai sau con cua S2"<< endl;

}