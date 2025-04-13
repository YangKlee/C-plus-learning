#include <bits/stdc++.h>
#define nullptr NULL
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
};
bool in(int x, Node *S){
    if(!S)
        return false;
    else
    {
        if(S->key == x)
            return true;
        else if(x < S->key){
            return in(x, S->left);
        }
        else{
            return in(x, S->right);
        }
    }

}
void insert(Node* &root, int x)
{
    if(!root)
    {
        root = new Node();
        root->key = x;
        root->left = nullptr;
        root->right =  nullptr;
    }
    else if(!in(x, root))
    {
        if(x < root->key)
            insert(root->left, x);
        else
        {
            insert(root->right, x);
        }
    }
}
void print(Node* root)
{
    if(root)
    {
        print(root->left);
        cout << root->key << endl;
        print(root->right);
    }
}
bool subset(Node* S1, Node* S2){
    if(!S1)
        return false;
    else
    {
        return (S1->left, S2) && (S1->right, S2) && in(S1->key , S2);
    }
}
// Giao 2 tập hợp
Node* intersectionSet(Node* S1, Node* S2, Node* S3){

    if(S1)
    {
        if(in(S1->key, S2))
        {
            insert(S3,S1->key);
        }
        S3 = intersectionSet(S1->left, S2, S3);
        S3 = intersectionSet(S1->right, S2, S3);
    }
    return S3;
}
//Hợp 2 tập hợp
Node* append(Node* S1, Node* S2){
    if(S1)
    {
        if(!in(S1->key, S2))
        {
            insert(S2, S1->key);
        }
        S2 = append(S1->left, S2);
        S2 = append(S1->right, S2);
    }
    return S2;
}
Node* unionSet(Node* S1, Node*S2)
{
    Node* S3 = nullptr;
        S3 = append(S1, S3);
        S3 = append(S2, S3);
        return S3;

}
//Tìm hiệu của hai tập hợp S1 và S2.
//duyệt từng số trong S1 nếu không thuộc S2 thì đưa vào tập kết quả S3
Node* differenceSet(Node* S1, Node* S2, Node* S3){
    if(S1)
    {
        if(!in(S1->key, S2))
            insert(S3, S1->key);
        S3 = differenceSet(S1->left, S2, S3);
        S3 = differenceSet(S1->right, S2, S3);
    }
    return S3;
}
//Viết hàm chuyển một mảng số nguyên vào tập hợp số nguyên
Node* arrToSet(int arr[], int n){
    Node* set = nullptr;
    for (int i = 0; i < n; i++)
    {
        insert(set, arr[i]);
    }
    return set;
}
void inOrder(Node* root, int arr[], int &index) {
    if (root != nullptr) {
        inOrder(root->left, arr, index);
        arr[index++] = root->key;
        inOrder(root->right, arr, index);
    }
}

int setToArr(Node* S, int arr[]){
    if(S)
    {
        int index = 0;
        inOrder(S, arr, index);
        return index; 
    }
}
int main()
{
    Node* setA = nullptr;
    Node* setB = nullptr;
    int A[] = {5,2,1,3,10, 40};
    int B[] = {-1,2,3,11,21, 22, 5, -5, 22};
    for(int x: A)
    {
        insert(setA, x);
    }
    print(setA);
    for(int x: B)
    {
        insert(setB, x);
    }
    print(setB);
    cout << "Giao cua hai tap hop la" << endl;
    print(intersectionSet(setA, setB, nullptr));
    cout << "Hop cua hai tap hop la" << endl;
    print(unionSet(setA, setB));
    cout << "Hieu cua hai tap hop la" << endl;
    print(differenceSet(setA, setB, nullptr));
    int arrOut[1000];
    int n =  setToArr(setA, arrOut);  
    for (int i = 0; i < n; i++)
    {
        cout << arrOut[i] << " ";
    }
}