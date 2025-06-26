#include <bits/stdc++.h>
using namespace std;
struct BST
{
    int data;
    BST* left;
    BST* right;
};
void initTree(BST* &root)
{
    BST* r8 = new BST{13, nullptr, nullptr};
    BST* r7 = new BST{14, r8, nullptr};
    BST* r6 = new BST{10, nullptr, r7};
    BST* r5 = new BST{7, nullptr, nullptr};
    BST* r4 = new BST{4, nullptr, nullptr};
    BST* r3 = new BST{6, r4, r5};
    BST* r2 = new BST{1, nullptr, nullptr};
    BST* r1 = new BST{3, r2, r3};
    root = new BST{8, r1, r6};

}
void print(BST *root)
{
    if(root != nullptr){
        cout << root->data << " " ;
        print(root->left);
        print(root->right);

    }
}
// tinh tong so chan trong cay
int sumChan(BST *root){
    if(root == nullptr)
        return 0;
    else
    {
        int sum = 0;
        if(root->data %2 == 0)
            sum += root->data;
        sum += sumChan(root->left);
        sum += sumChan(root->right);
        return sum;
    }
}
// cap so x trong cay
int capsoX(BST* root, int x, int h)
{
    if(root == nullptr)
        return 0;
    else
    {
        if(root->data == x)
            return h;
        int rootLeft = capsoX(root->left, x, h+1);
        if(rootLeft != 0)
            return rootLeft;
        else
        {
            int rootRight = capsoX(root->right, x, h+1);
            if(rootRight != 0)
                return rootRight;
            else
                return 0;
        }
    }
}
int main()
{
    BST* root = new BST();
    initTree(root);

    print(root);
    cout << "Tong so chan trong cay: " << sumChan(root) << endl;
    cout << "Cap so 6 trong cay: " << capsoX(root,88, 0) << endl;
}
