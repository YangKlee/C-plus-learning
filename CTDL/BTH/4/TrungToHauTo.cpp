#include <bits/stdc++.h>
using namespace std;
int isUuTien(char c)
{
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
string convertHauTo(string trungto)
{
    stack<char> stk;
    string hauto = "";
    for (char x: trungto)
    {

        if (x == '+' || x == '-' || x == '*'|| x =='/')
        {
            while (!stk.empty() &&(isUuTien(stk.top()) >= isUuTien(x)) && stk.top() != '(' ){
                hauto += stk.top();
                stk.pop();
            }
            stk.push(x);
        }
        else if (x == '(')
        {
            // ngoac mo thi dua vao stack
            stk.push(x);
        }
        else if(x == ')')
        {
            // lay lan luot cac phan tu o dau ngan xep dua vao bieu thuc hau to den khi gap dau ngoac mo
            while(!stk.empty() && stk.top() != '(' )
            {
                hauto+= stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else{
             // toan hang thi dua vao hau to
            hauto += x;
        }
    }
    while(!stk.empty())
    {
        hauto+= stk.top();
        stk.pop();
    }
    return hauto;
}
int tinhHauTo(string hauto)
{
    stack <int> tmp;
    stack <int> result;
    for (char c:hauto)
    {
        if (c == '+' || c == '-' || c == '*'|| c =='/')
        {
            tmp.push(result.top());
            result.pop();
            tmp.push(result.top());
            result.pop();

            int a = tmp.top(); tmp.pop();
            int b = tmp.top(); tmp.pop();
            int kq;
            if (c == '+')
            {
                kq = a + b;
            }
            else if(c == '-')
            {
                kq =a - b;
            }
            else if(c == '*')
            {
                kq = a * b;
            }
            else if(c == '/')
            {
                kq = a / b;
            }
            result.push(kq);
        }
        else
        {
            result.push(c - '0');
        }
    }
    return result.top();

}
int main()
{
    string bt = "5+(7-2)*3-8/2+1";
    string hauto =  convertHauTo(bt);
    cout << hauto << endl;
    cout << tinhHauTo(hauto);
}
