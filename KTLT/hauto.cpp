#include <bits/stdc++.h>
using namespace std;
stack <char> stk;
// ham tra ve do uu tien phep toan
int getUuTien(char x)
{
    if (x =='*' ||  x == '/')
        return 2;
    else if (x =='+' ||  x == '-')
        return 1;
    else
        return 0;
}
string getStack(string bieuThuc, char toanTu)
{
    string result = "";
    // mang tam chua nhung phan tu khong duoc dua vao ket qua
    stack <char> tmp;
    while (stk.size() > 0 )
    {
        char tmp1 = stk.top();
        // gioi han cho phep chi dua cac toan tu trong ngoac vao ket qua
        if (tmp1 == '(')
            break;
        else
        {
            if((getUuTien(tmp1) >= getUuTien(toanTu)) )
                result = result + tmp1;
            else
                tmp.push(tmp1);
            stk.pop();
        }
    }
    // sao chep cac phan tu mang tmp vao mang stk
    while (tmp.size() > 0)
    {
        stk.push(tmp.top());
        tmp.pop();
    }
    //stk = tmp;
    stk.push(toanTu);
    return result;
}
string clearStk()
{
    string result = "";
    while(stk.size() >0)
    {
        if(stk.top() != '(' &&stk.top() != ')')
            result = result + stk.top();
        stk.pop();
    }
    return result;
}
string chuyenTrungTo(string bieuThuc)
{
    string result = "";
    for (int i = 0; i < bieuThuc.length(); i++)
    {
        // toan hang thi them truc tiep vao ket qua
        if (bieuThuc[i] >= '0' && bieuThuc[i] <= '9')
            result = result + bieuThuc[i];
        // dau ngoac ( thi them vao stack
        else if(bieuThuc[i] == '(')
            stk.push('(');
        // dau ngoac ( thi lay tat ca phan tu them vao ket qua den khi gap dau (
        else if(bieuThuc[i] == ')')
        {
            while (stk.top() != '(')
            {
                result = result + stk.top();
                stk.pop();
            }
            // xoa dau ( de tranh xung dot doi voi bieu thuc nhieu dau ngoac
            stk.pop();
        }
        // toan tu thi xu li rieng
        else if (bieuThuc[i] == '+' ||bieuThuc[i] == '-'
                 ||bieuThuc[i] == '*'||bieuThuc[i] == '/')
        {
            result = result + getStack(bieuThuc, bieuThuc[i]);
        }
    }
    // dua tat ca phan tu trong stack vao ket qua
    result += clearStk();
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    string bieuThuc;
    for(int i = 0; i < n; i++)
    {
        getline(cin, bieuThuc);
        cout << chuyenTrungTo(bieuThuc) << endl;
    }
}