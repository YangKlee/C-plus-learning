#include <bits/stdc++.h>
using namespace std;
struct Word
{
    string English;
    string Vietnamese;
};
struct EngVietDict
{
    Word data;
    EngVietDict *left, *right;
};
typedef EngVietDict Tree;
void insertWord(Tree *&root, Word data)
{
    if (root == nullptr)
    {
        root = new Tree;
        root->data  = data;
        root->left = root->right = NULL;
    }
    else if (data.English < root->data.English)
        insertWord(root->left, data);
    else if(data.English > root->data.English)
        insertWord(root->right, data);
}
void readDictFromFile(Tree *&root, string fileName)
{
    ifstream fin(fileName);
    string rawData;
    while(getline(fin, rawData))
    {
        Word tmp;
        stringstream ss(rawData);
        getline(ss, tmp.English, ':');
        getline(ss, tmp.Vietnamese, ':');
        insertWord(root, tmp);
        ss.clear();
    }
}
string findVietnamese(Tree *root, string eng)
{
    if(!root)
        return "Khong tim thay tu";
    else
    {
        if(root->data.English == eng)
            return root->data.Vietnamese;
        else
        {
            if(eng < root->data.English)
                return findVietnamese(root->left, eng);
            else
                return findVietnamese(root->right, eng);
        }
    }
}
void printDic(Tree * root)
{
    if(root)
    {
        printDic(root->left);
        cout << root->data.English << " : " << root->data.Vietnamese << endl;
        printDic(root->right);
    }
}
void printWordByH(Tree* root)
{
    if(root)
    {
        printWordByH(root->left);
        if(root->data.English[0] == 'H')
        {
            cout << root->data.English << " : " << root->data.Vietnamese << endl;
        }
        printWordByH(root->right);
    }
    
}

Tree* findWord(Tree *root, string word)
{
    if(!root)
        return nullptr;
    else
    {
        if(root->data.English == word)
            return root;
        else
        {
            if(word < root->data.English)
                return findWord(root->left, word);
            else
                return findWord(root->right, word);
        }
    }
}
int countWord(Tree *root)
{
    if(!root)
        return 0;
    else
    {
        return countWord(root->left) + countWord(root->right) + 1;
    }
}
int countAfterAWord(Tree *root, string word)
{
    if(!root)
        return 0;
    else
    {
        Tree* target = findWord(root, word);
        return countWord(target->left) + countWord(target->right);

    }
}
int main()
{
    Tree *td = nullptr;
    readDictFromFile(td, "word.txt");

    int choice = 0;
    do{
        cout << "Menu" << endl;
        cout << "1.In tu dien" << endl;
        cout << "2.Tra tu dien" << endl;
        cout << "3.Chon tu bat dau bang tu H" << endl;
        cin >> choice;
        if (choice == 1)
        {
            printDic(td);
        }
        if (choice == 2)
        {
            string inp;
            cout << "Nhap tu tieng anh" ;
            cin.ignore();
            getline(cin, inp);
            cout << "Nghia cua tu la" << findVietnamese(td, inp) << endl;
        }
        if(choice == 3)
        {
            printWordByH(td);
        }
        if(choice == 4)
        {
            string inp;
            cout << "Nhap tu tieng anh" ;
            cin.ignore();
            getline(cin, inp);
            cout << countAfterAWord(td, inp );
        }
    }
    while(choice != 0);
}

