#include <bits/stdc++.h>
using namespace std;
struct Person
{
    string name;
    int yearOfBirth;
};
struct  BFT
{
    Person data;
    BFT *left, *right;  
};
BFT* createNode(Person p , BFT* left, BFT* right)
{
    return new BFT{p, left, right};
}
//create the specify BFT
BFT* createBFT()
{
    BFT *n1, *n2, *n3, *n4, *n5, *n6;
    n1 = createNode({"Nguyen Khanh Duong", 2005}, nullptr, nullptr);
    n2 = createNode({"Nguyen Yen Nhi", 2005}, nullptr, n1);
    n3 = createNode({"Trinh Tran Phuong Tuan", 1965}, nullptr, nullptr);
    n4 = createNode({"Huynh Ngoc Khang", 2005}, nullptr, nullptr);
    n5 = createNode({"Tran Thanh Cuong", 1935}, n3, n4);
    n6 = createNode({"Bui Ngoc Toan", 1900}, n2, n5);
    return n6;
}
//prints a binary family tree in a pre-order traversal
void printBFT(BFT* root)
{
    if (root)
    {
        cout << root->data.name << " " << root->data.yearOfBirth << endl;
        printBFT(root->left);
        printBFT(root->right);
    }
}
void 
int main()
{

}