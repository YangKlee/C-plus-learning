#include <bits/stdc++.h>
using namespace std;
struct CBF // char binary tree
{
    char c;
    CBF* left;
    CBF* right;

};
int main()
{
    CBF *b, *c, *d, *e, *f, *g;
    g = new CBF{'G', nullptr, nullptr};
    f = new CBF{'F', nullptr, nullptr};
    e = new CBF{'E', nullptr, nullptr};
    d = new CBF{'D', nullptr, nullptr};
    c = new CBF{'C', f, g};
    b = new CBF{'B', d, e};
    CBF* root = new CBF{'A', b, c};

}