#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    vector <int> tree;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        tree.push_back(tmp);
    }
    int min = tree[0];
    int min_index = 0;
    for(int i = 0; i< tree.size(); i++)
    {

        for(int j = 1; j < tree.size(); j++)
        {
            if(tree[j] < min)
            {
                min_index = j;
                min = tree[j];
            }
        }
        swap(tree[i], tree[min_index]);
    }
    for(int x: tree)
    {
        cout << x << ' ';
    }
    
}