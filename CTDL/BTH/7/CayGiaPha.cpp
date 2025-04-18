#include <bits/stdc++.h>
using namespace std;
struct Person
{
    string name;
    int yearOfBirth;
};
struct FT
{
    Person data;
    FT *child, *sibling;

};
typedef FT Node;
int countPerson(Node* root)
{
    if(!root)
        return 0;
    else
    {
        return 1+ countPerson(root->sibling) + countPerson(root->child);
    }
}
int countTheHe(Node* root)
{
    if(!root)
        return 0;
    else
    {
        int child = countTheHe(root->child)+1;
        int sib = countTheHe(root->sibling);
        return max(child, sib);
    }
}
void print(Node* root)
{
    if(root)
    {
        print(root->child);
        cout << root->data.name << " " << root->data.yearOfBirth << endl;
        print(root->sibling);
    }
}
// Tìm một người tên x trong cây gia phả
Node* findNameX(Node* root, string x)
{
    if(!root)
    {
        return nullptr;
    }
    else
    {
        if(root->data.name == x)
        {
            // cout << "Found X" << endl;
            return root;

        }
        Node* child = findNameX(root->child, x);
        if(child)
            return child;
        return findNameX(root->sibling, x);
    }
}
bool isSib(Node* root, string y)
{
    if(!root)
        return false;
    else
    {
        if(root->data.name == y)
        {
            // cout << "Found Y" << endl;
            return true;
        }
        return isSib(root->sibling, y);
    }
}
//Kiểm tra người tên y có phải con người tên x không?
bool isYChildX(Node* root, string y, string x)
{
    Node* X = findNameX(root, x);
    if(X && isSib(X->child, y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Tính thế hệ của người tên x
int theHeX(Node* root, string x)
{
    int tongTheHe = countTheHe(root);
    Node* X = findNameX(root, x);
    if(!X)
        return 0;
    return tongTheHe - countTheHe(X) +1;

}
//Liệt kê tất cả những người con của người tên x
void printConX(Node* root, string x)
{
    Node* X = findNameX(root, x);
    X = X->child;
    if(!X)
        return;
    else
    {
        while(X)
        {
            cout << X->data.name << " " << X->data.yearOfBirth << endl;
            X = X->sibling;
        }
    }
}
//In những người thuộc thế hệ thứ k.
void printByLevel(FT* root, int k, int curr){
    if(!root)
        return;
    else
    {
        printByLevel(root->child, k, curr+1);
        if(curr == k)
            cout << root->data.name << " " << root->data.yearOfBirth << endl;
        printByLevel(root->sibling, k, curr);
    }
}
// Cho biết người tên x và y có phải là anh em không?
bool isSibling(Node* root, string x, string y)
{
    Node* X = findNameX(root, x);
    if(X)
    {
        while(X)
        {
            if(X->data.name == y)
                return true;
            X = X->sibling;
        }
    }
    return false;
}
//Thêm người q vào con của người tên x trong cây. Biết rằng các nút con của một người
//được sắp theo thứ tự tăng của năm sinh.
void insertChild(FT* root, string x, Person q){
    Node* X = findNameX(root, x);
    Node* newNode = new Node();
    newNode->sibling = nullptr;
    newNode->data = q;
    if(!X->child)
    {
        X->child = newNode;
    }
    else{
        // chen o head
        if(X->child->data.yearOfBirth > q.yearOfBirth)
        {
            newNode->sibling = X->child;
            X->child = newNode;
            return;
        }
        X = X->child;

        Node* prev = X;
        if(!X->sibling)
        {
            X->sibling = newNode;
            return;
        }
        
        X = X->sibling;
        while (X)
        {
            if(X->data.yearOfBirth > q.yearOfBirth)
            {
                newNode->sibling = prev->sibling;
                newNode->child = prev->child;
                prev->sibling = newNode;
                return;
            }
            X = X->sibling;
            prev = prev->sibling;
        }
        newNode->sibling = prev->sibling;
        prev->sibling = newNode;
    }
}
//Liệt kê con, cháu của một người có họ tên x.
void printDescendants(FT* root, string x){
    Node* X = findNameX(root, x);
    print(X->child);
}
int countSib(Node* root)
{
    if(!root)
        return 0;
    return countSib(root->sibling) + 1;
}
//Tính bậc của cây.
int degree(FT* root){
    if(!root)
        return 0;
    else
    {
        int curr = countSib(root->child);
        int child = degree(root->child);
        int sib = degree(root->sibling);
        return max(curr, max(child, sib));
    }
}
int main()
{
    Node *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
    p8 = new Node{{"Nguyen Yen Nhi", 2005}, nullptr, nullptr};
    p7 = new Node{{"Nguyen Van H", 1970}, p8, nullptr};
    p6 = new Node{{"Nguyen Van G", 1965}, nullptr, p7};
    p5 = new Node{{"Nguyen Van F", 1965}, nullptr, nullptr};
    p4 = new Node{{"Nguyen Van E", 1960}, nullptr, p5};
    p3 = new Node{{"Nguyen Van D", 1955}, nullptr, p4};
    p2 = new Node{{"Nguyen Van C", 1935}, p6, nullptr};
    p1 = new Node{{"Nguyen Van B", 1930}, p3, p2};
    Node* root = new Node{{"Nguyen Van A", 1900}, p1, nullptr};

    cout << countPerson(root) << endl;
    cout << countTheHe(root)<< endl;
    cout << isYChildX(root, "Nguyen Van D", "Nguyen Van B") << endl;
    cout << theHeX(root, "Nguyen Van H") << endl;
    printConX(root,"Nguyen Van B");
    printByLevel(root, 3, 1);
    cout << isSibling(root, "Nguyen Van D", "Nguyen Van F")<< endl;
    insertChild(root, "Nguyen Van C", {"Nguyen Khanh Duong", 1966});
    printConX(root,"Nguyen Van C");
    cout << endl;
    print(root);
    cout << degree(root) << endl;
}