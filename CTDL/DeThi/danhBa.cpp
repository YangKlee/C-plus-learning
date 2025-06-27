#include <bits/stdc++.h>
using namespace std;
struct User
{
    string phone;
    string name;
};
struct DB
{
    User data;
    DB* left;
    DB* right;
};
// tra ve true neu a > b
bool comprPhone(string a, string b)
{
    if(a.length() > b.length())
        return 1;
    else if(a.length() < b.length())
        return 0;
    else
    {
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] > b[i])
                return 1;
            else if(a[i] < b[i])
                return 0;
        }
        return 1;
    }
}
void add(DB* &root, User data)
{
    if(!root)
    {
        DB* newDB = new DB();
        newDB->data = data;
        newDB->left = nullptr;
        newDB->right = nullptr;
        root = newDB;
    }
    else
    {
        if(comprPhone(root->data.phone , data.phone))
        {
            add(root->left, data);
        }
        else
        {
            add(root->right, data);
        }
    }
}
void print(DB* root)
{
    if(root)
    {
        cout << root->data.phone << " ; " << root->data.name << endl;
        print(root->left);
        print(root->right);
    }
}
void readFromFile(DB* &root,string filename)
{
    ifstream f(filename);
    string rawData;
    while(getline(f,rawData))
    {
        User newUser;
        stringstream ss(rawData);
        getline(ss, newUser.phone,',');
        getline(ss, newUser.name, ',');
        add(root, newUser);
        ss.clear();
    }
    f.close();
}
// cho biet so dien thoai X co trong cay khong
bool isContainPhone(DB* root, string x)
{
    if(!root)
        return false;
    else
    {
        if(root->data.phone == x)
            return true;
        bool isContainLeft = isContainPhone(root->left, x);
        if(!isContainLeft)
        {
            return isContainPhone(root->right, x);
        }
        else
        {
            return isContainLeft;
        }
    }
}
bool isStartWith(string s, string start)
{
    for (int i = 0; i < start.length(); i++)
    {
        if(s[i] != start[i])
            return false;
    }
    return true;
}
// liet ke so dien thoai bat dau bang x
void lietKePhone(DB *root, string x)
{
    if(root)
    {
        if(isStartWith(root->data.phone, x))
        {
            cout << root->data.phone << endl;
        }
        lietKePhone(root->left, x);
        lietKePhone(root->right, x);
    }
}
DB* findPhone(DB* root, string phone)
{
    if(!root)
        return nullptr;
    else
    {
        if(root->data.phone == phone)
            return root;
        else if(comprPhone(root->data.phone, phone))
        {
            return findPhone(root->left, phone);
        }
        else{
            return findPhone(root->right, phone);
        }
    }
}
DB* findNodeMax(DB* root)
{
    if(root == nullptr)
    {
        return nullptr
    }
    else if(!root->right)
    {
        return root;
    }
    else
    {
        return findNodeMax(root->right);
    }
}
DB* findNodeMin(DB* root)
{
    if(root == nullptr)
    {
        return nullptr
    }
    else if(!root->left)
        return root;
    else
    {
        return findNodeMin(root->left);
    }
}

int main()
{
    DB* root = nullptr;
    readFromFile(root, "dataPhone.txt");
    print(root);
    cout << isContainPhone(root, "0995566778") << endl;
    cout << "So dien thoai bat dau bang 099" << endl;
    lietKePhone(root, "09999");
}
