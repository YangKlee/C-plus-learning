#include <bits/stdc++.h>
using namespace std;
int n;
int dem = 0;
vector <int> v;
void inilazie()
{
    for (int i = 1; i <= n; i++)
    {
        v[i] = 1;
    }
}
void show()
{
    cout << "Nghiem la: ";
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " "; 
    }
    cout << endl;
}
void stop()
{
    if (dem == 0)
        cout << "Vo nghiem" << endl;
    else
        cout << dem <<" nghiem da tim thay" << endl;
    exit(1); // dung chuong trinh
}
// ham quay lui lai quan hau thu k
int back(int k)
{
    int tmp;
    for (int i = k; i >= 1; i--)
    {
        if (v[i] < n)
        {
            v[i] +=1;
            tmp = i;
            break;
        }
        else if (v[1] == n)
            stop();
    }
    for (int i = tmp +1 ; i <= n; i++)
    {
        v[i] = 1;
    }
    return tmp;
    
}
bool isEat(int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        // kiem tra xem co quan hau nao cung hang voi cung duong cheo hay khong!
        if (v[i] == v[k] || abs(v[i] - v[k]) == abs(i - k))
            return true;
    }
    return false;
}

void queenBackTracking()
{
    inilazie();
    int k = 1; // k la quan hau thu k (1 den n)
    while (1)
    {
        if (k > n)
        {
            dem++;
            show();
            // thuc hien gia sai, quay lui 
            k = back(k - 1);
            continue;            
        }
        else 
        {
            while (1)
            {
                // khi khong tim thay solution tren cot, quay lui 
                if (v[k] > n)
                    k = back(k- 1);
                else if (isEat(k))
                    v[k] +=1;
                else
                    break;
            }
            k++;
        }

    }
}
int main()
{
    cin >> n;
    v.resize(n+1);
    queenBackTracking();
}