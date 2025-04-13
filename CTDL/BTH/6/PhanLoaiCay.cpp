#include <bits/stdc++.h>
#define nullptr NULL
using namespace std;
struct Node{
    int key;
    Node *left, *right;
};

void convertToVector(Node* root, vector<int> &a)
{
    if(!root)
        return ;
    else
    {

        convertToVector(root->left, a);
        a.push_back(root->key);
        convertToVector(root->right, a);
    }
}
bool isSearchBinary(Node* root)
{
    // check vector tang dan
    vector<int>a ;
    convertToVector(root, a);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i+1; j < a.size(); j++)
        {

            if(a[i] > a[j])
                return false;
        }
    }
    return true;
}
int height(Node* root)
{
    if(!root)
        return 0;
    else
    {
        return height(root->left) + height(root->right) + 1;
    }
}
bool isBalancedTree(Node* root){
    if(!root)
    {
        return true;
    }
    else
    {
        if(abs(height(root->left) - height(root->right)) > 1)
            return false;
        bool left = isBalancedTree(root->left);
        if(!left)
            return left;
        else
            return isBalancedTree(root->right); 
    }
}
bool isCompleteBalancedTree(Node* root){
    if(!root)
    {
        return true;
    }
    else
    {
        if(height(root->left) != height(root->right))
            return false;
        bool left = isCompleteBalancedTree(root->left);
        if(!left)
            return left;
        else
            return isCompleteBalancedTree(root->right); 
    }
}
int main()
{

    Node* n7 = new Node({10, nullptr, nullptr});
    Node* n6 = new Node({8, nullptr, n7});
    Node* n5 = new Node({6, nullptr, n6});
    Node* n2 = new Node({2, nullptr, nullptr});
    Node* n1 = new Node({1, nullptr, n2});
    Node* root = new Node({4, n1, n5});
    cout << isSearchBinary(root) << endl;
    Node* s1 = new Node({1, nullptr, nullptr});
    Node* s3 = new Node({3, nullptr, nullptr});
    Node* s2 = new Node({2, s1, s3});
    
    Node* s5 = new Node({5, nullptr, nullptr});
    Node* s7 = new Node({7, nullptr, nullptr});
    Node* s6 = new Node({6, s5, nullptr});
    Node* s4 = new Node({4, s2, s6});
    
    Node* s9 = new Node({9, nullptr, nullptr});
    Node* s11 = new Node({11, nullptr, nullptr});
    Node* s10 = new Node({10, s9, s11});
    
    Node* s13 = new Node({13, nullptr, nullptr});
    Node* s15 = new Node({15, nullptr, nullptr});
    Node* s14 = new Node({14, nullptr, s13});
    Node* s12 = new Node({12, s10, s14});
    
    Node* root_2 = new Node({8, s4, s12});
    cout << isBalancedTree(root_2) << endl;
    Node* u1 = new Node{1, nullptr, nullptr};
    Node* u3 = new Node{3, nullptr, nullptr};
    Node* u5 = new Node{5, nullptr, nullptr};
    Node* u7 = new Node{7, nullptr, nullptr};
    Node* u2 = new Node{2, u1, u3};
    Node* u6 = new Node{6, u5, u7};
    Node* root_3 = new Node{4, u2, u6};
    cout << isCompleteBalancedTree(root_3) << endl;
}