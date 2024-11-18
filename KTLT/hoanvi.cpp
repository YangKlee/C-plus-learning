#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> s;
vector <int> dic;
vector <bool> isUse;
void inilazie()
{
    s.resize(n, 0);
    isUse.resize(n+1, false);
    for (int i = n; i >= 1 ; i--)
    {
        dic.push_back(i);
    }
    cout << "inilazie complete" << endl;
}
void show()
{
    for (int x:s)
    {
        cout << x << " ";
    }
    cout << '\n';
}

int back()
{
    // quay ve truoc vi tri phan tu cuoi cung trong dic
    int pos;
    for (int i = s.size() - 1; i >= 0; i--)
    {

        if (s[i] == dic[dic.size()- 1])
        {
            if (i == 0)
                return -1;
            pos = i;
        }
    }
    // reset
    for (int i = pos; i < n; i++)
    {
        isUse[s[i]] = 0;
    }
    isUse[s[pos-1]] = 0;
    s[pos-1] = dic[dic.size()- 1];
    isUse[dic[dic.size()- 1]] = 1;
    cout << "Back : return value " << pos<< endl;
    return pos;
    
}
int main()
{
    cin >> n;
    inilazie();
    
    int i = 0;
    while(1)
    {
        //for (int i = checkpoint; i <= s.size(); i++)
        {
            //cout << i << endl;
            if (i == s.size())
            {
                show();
                i = back();
                if (i == -1)
                    break;
                else
                    continue;
            }
            for (int j = 0; j < dic.size(); j++)
            {
                if (!isUse[dic[j]])
                {
                    s[i] = dic[j];
                    isUse[dic[j]] = 1;
                    break;
                }
            }
        }
        i++;
    }
}