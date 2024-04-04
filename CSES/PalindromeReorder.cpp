#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    string b;
    string du;
    set <char> list;
    vector <char> list_char;
    vector <int> solan;
    getline(cin,a);
    bool stack = false;
    for(char i = 'A'; i <='Z'; i++)
    {
        
        int count = 0;
        for(int j = 0; j < a.length(); j++)
        {
            //cout << i << (char)a[j]
            if(i == (char)a[j])
                count ++;
        }
        if(count %2 != 0 && a.length()%2 != 0 )
        {
            if(stack == false)
            {
                stack = true;
                if(count != 0 && list.count(i) == 0){
                    list.insert(i);
                    du = i;
                    list_char.push_back(i);
                    solan.push_back(count);
                }
            }
            else
            {
                cout << "NO SOLUTION";
                exit(0);
            }
        }
        else if(count %2 != 0 && a.length()%2 == 0)
        {
            cout << "NO SOLUTION";
            exit(0);
        }
        else
        {
                if(count != 0 && list.count(i) == 0){
                    list.insert(i);
                    list_char.push_back(i);
                    solan.push_back(count);
                }
        }
        //cout << count<< endl;
    }
    for(int i = 0; i < list.size(); i++)
    {
        for(int j = 0; j < solan[i]/2; j++)
        {
            b.push_back(list_char[i]);
        }
    }
    string chuoidao = b;
    reverse(chuoidao.begin(), chuoidao.end());
    if(a.length()%2 == 0)
        cout << b << chuoidao; 
    else
        cout << b<< du<< chuoidao; 

}