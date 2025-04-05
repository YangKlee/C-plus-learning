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
    BFT *left;
    BFT *right;  
};
BFT* createNode(Person p , BFT* left, BFT* right)
{
    return new BFT{p, left, right};
}
//create the specify BFT
BFT* createBFT()
{
    BFT *root, *n1, *n2, *n3, *n4, *n5, *n6;
    n6 = createNode({"Nguyen G", 1970}, nullptr, nullptr);
    n5 = createNode({"Nguyen F", 1970}, nullptr, nullptr);
    n4 = createNode({"Nguyen E", 1965}, nullptr, nullptr);
    n3 = createNode({"Nguyen D", 1960}, nullptr, n6);
    n2 = createNode({"Nguyen C", 1935}, n4, n5);
    n1 = createNode({"Nguyen B", 1930}, nullptr, n3);
    root = createNode({"Nguyen A", 1990}, n1, n2);
    return root;
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
//Đếm số người trong cây.
int countPersons(BFT* root){
    if(!root)
    {
        return 0;
    }
    else
    {
        return 1 + countPersons(root->left) + countPersons(root->right);
    }
}
// Tính số thế hệ của cây
int height(BFT* root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        int left = height(root->left);
        int right = height(root->right);
        if (left > right)
            return 1 + left;
        else
            return 1+ right;
    }
}
//Đếm số người sinh trước năm x
int countPersonsLessThan(BFT* root, int year){
    if(!root)
    {
        return 0;
    }
    else
    {
        if (root->data.yearOfBirth < year)
        {
            return countPersonsLessThan(root->left , year) + countPersonsLessThan(root->right, year) + 1;
        }
        else
        {
            return countPersonsLessThan(root->left, year) + countPersonsLessThan(root->right, year) ;
        }
    }
}
//find a person in BFT by name
BFT* findPerson(BFT* root, string name){
    if(!root) {
        return nullptr;
    }
    else
    {
        if(root->data.name == name)
            return root;
        BFT* left = findPerson(root->left, name);
        if(left)
            return left;
        return findPerson(root->right, name);
    }
}
//check pName is parent of cName
bool isParent(BFT* root, string pName, string cName)
{
    if(!root)
        return false;
    else
    {
        BFT* parent = findPerson(root, pName);
        if(!parent)
            return false;
        else
        {
            return(parent->left && parent->left->data.name == cName) || 
                (parent->right && parent->right->data.name == cName) ;
        }
    }
}
//Cho biết người tên x thuộc thế hệ thứ mấy trong cây.
int levelOfPerson(BFT* root, string name){
    if(!root)
        return 0;
    else if (root->data.name == name)
        return 1;
    else
    {
        int left = levelOfPerson(root->left, name);
        if (left)
        {
            return left;
        }
        else
        {
            int right = levelOfPerson(root->right, name);
            if (right)
            {
                return right + 1;
            }
            else
            {
                return 0;
            }
        }
    }
}
//Kiểm tra người tên y có phải con cháu của người tên x không?
bool isDescendants(BFT* root, string x, string y){
    BFT* parent = findPerson(root, x);
    if(findPerson(parent, y) != nullptr)
        return 1;
    return 0;
}
//Liệt kê tất cả con cháu của người tên x.
void printDescendants(BFT* root, string x){
    BFT* parent = findPerson(root, x);
    printBFT(parent->left);
    printBFT(parent->right);
}
// Thay người tên x bằng một người khác trong cây gia phả.
void setPerson(BFT* root, string x, Person p){
    BFT *target = findPerson(root, x);
    target->data = p;
}


//Kiểm tra hai người tên x, y có phải anh em không?
bool isSibling(BFT* root, string x, string y){
    if(!root)
        return false;
    else
    {
        bool left = isSibling(root->left, x, y);
        //BFT* right = isSibling(root->right, x, y);
        if (root->left && root->left->data.name == x && root->right &&root->right->data.name == y)
        {
            return true;
        }
        if(left)
            return left;
        else
            return isSibling(root->right, x, y);
    }
}
//Liệt kê những người trong cây thuộc thế hệ thứ k
void printPersonsAtLevel(BFT* root, int k, int currLevel){
    if(root)
    {
        if(currLevel == k)
            cout << root->data.name << endl;
        printPersonsAtLevel(root->left, k, currLevel+1);
        printPersonsAtLevel(root->right, k, currLevel+1);
    }
}
//Kiểm tra hai cây gia phả có giống nhau không?
bool isSameBFT(BFT* root1, BFT* root2){
    if(!root1 || !root2)
    {
        return false;
    }
    else
    {
        if(root1->data.name == root1->data.name && root1->data.yearOfBirth == root2->data.yearOfBirth)
        {
            return true;
        }
        else
        {
            return false;
        }
        bool left = isSameBFT(root1->left, root2->left);
        if(left)
            return left;
        else
            return isSameBFT(root1->right, root2->right);
    }
}
//Thêm người ng vào con của người tên x. Nếu người tên x đã đủ 2 con thì không thêm.
bool addPerson(BFT* root, string x, Person p){
    BFT* target = findPerson(root, x);
    BFT* newNode = createNode(p, nullptr, nullptr);
    if(!target->left)
    {
        target->left = newNode;
        return 1;

    }
    else if(!target->right)
    {
        target->right = newNode;
        return 1;

    }
    else
    {
        delete newNode;
        return 0;
    }
    
}
int main()
{
    BFT* data = createBFT();
    printBFT(data);
    cout << "Sum of person is: " << countPersons(data) << endl;
    cout << "So the he la: " << height(data) << endl;
    //int x; cin >> x;
    //cout << "So nguoi sinh truoc nam " << x << " la: " << countPersonsLessThan(data, x) << endl;
    BFT* tmp = findPerson(data, "Nguyen B");
    printBFT(tmp);
    cout << isParent(data, "Nguyen C", "Nguyen E") << endl;
    cout << levelOfPerson(data, "Nguyen G") << endl;
    cout << isDescendants(data, "Nguyen A", "Nguyen G") << endl;
    printDescendants(data, "Nguyen C");
    cout << isSibling(data, "Nguyen B", "Nguyen C") << endl;
    printPersonsAtLevel(data, 4, 1);
    cout << isSameBFT(data, data) << endl;
    if(addPerson(data, "Nguyen D", {"Nguyen Khanh Duong", 2005})){
        cout << "Them nguoi thanh cong! Danh sach sau khi them:" << endl;
        printBFT(data);
    }
    else
    {
        cout << "Them nguoi that bai" << endl;
    }
    Person p = {"Nguyen Yen Nhi", 2005};
    setPerson(data, "Nguyen F", p);
    cout << "Danh sach sau khi thay the " << endl;
    printBFT(data);
    //cout << isDescendants(data, "Nguyen D", "Nguyen Khanh Duong") << endl;

}