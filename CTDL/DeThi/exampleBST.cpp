#include <bits/stdc++.h>
using namespace std;
struct BinaryTreeNode
{
    int key;
    BinaryTreeNode *left, *right;
};
void add(BinaryTreeNode* &root ,int x)
{   
    if(!root)
    {
        root = new BinaryTreeNode();
        root->key = x;
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        if(x > root->key)
            return add(root->right, x);
        else
            return add(root->left, x);
    }
}
void print(BinaryTreeNode *root)
{
    if(root)
    {
        print(root->left);
        cout << root->key << " ";
        print(root->right);
    }
}

int sum(BinaryTreeNode *root)
{
    if(!root)
        return 0;
    else
    {
        // tính tổng cây con bên trái của cây nhị phân
        int sumLeft = sum(root->left);
        // tính tổng cây con bên phải cây nhị phân
        int sumRight = sum(root->right);
        return root->key + sumLeft + sumRight;
    }
}
int min(BinaryTreeNode *root)
{
    if(!root)
        return nullptr;
    // nút hiện tại nằm ở bên trái cùng của cây
    else if(!root->left)
        return root->key;
    else
        return min(root->left);
}
int max(BinaryTreeNode *root)
{
    if(!root)
        return nullptr;
    // nút hiện tại nằm ở bên phải cùng của cây
    else if(!root->right)
        return root->key;
    else
        return max(root->right);
}
int capSoX(BinaryTreeNode *root, int x, int k)
{
    if(!root)
        return -1;
    else
    {
        if(root->key == x)
            return k;
        int capXLeft = capSoX(root->left, x, k+1);
        if(capXLeft != -1)
        {
            return capXLeft;
        }
        else
        {
            return capSoX(root->right, x, k+1);
        }
    }
}
// vd đếm trong cây có bao nhiêu số chẵn
int countDieuKien(BinaryTreeNode *root)
{
    if(!root)
        return 0;
    else
    {
       int countLeft = countDieuKien(root->left);
       int countRight = countDieuKien(root->right);
       // nếu thỏa điều kiện thì tổng hợp kết quả và cộng 1
       if(root->key %2 == 0)
            return countLeft + countRight + 1;
        else
            return countLeft + countRight;            
    }
}
int main()
{
    BinaryTreeNode *root = nullptr;
    add(root,1);
    add(root, 8);
    add(root, 0);
    add(root,7);
    add(root,2);
    add(root,5);
    print(root);
}