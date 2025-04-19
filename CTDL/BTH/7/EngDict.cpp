#include <bits/stdc++.h>
using namespace std;
#define nullptr NULL
struct EngDict{
    EngDict* child[27];
};
EngDict* initDict()
{
    EngDict* root = new EngDict();
    for(int i = 0; i < 27; i++)
    {
        root->child[i] = nullptr;
    }
    return root;
}
//Đọc một từ điển từ tệp:
void insertWord(EngDict* root, string w){
    EngDict* p = root;
    int j;
    for (char c: w)
    {
        j = c - 'a';
        if(p->child[j])
        {
            p = p->child[j];
        }
        else
        {
            p->child[j] = new EngDict;
            p = p->child[j];
            for(int i = 0; i < 27; i++)
            {
                p->child[i] = nullptr;
            }
        }
    }
    if(!p->child[26])
    {
        p->child[26] = new EngDict;
        p = p->child[26];
        for(int i = 0; i < 27; i++)
        {
            p->child[i] = nullptr;
        }
    }
    else
    {
        cout << "Duplicated word " << w << endl;
    }

}
//Đọc một từ điển từ tệp:
int readDictFromFile(string fileName, EngDict* root){
    ifstream file(fileName);
    string line;
    int count = 0;
    while (getline(file, line))
    {
        insertWord(root, line);
        count++;
    }
    file.close();
    return count;
}
//In từ điển
void printEngDict(EngDict *root, string w){
    if(root->child[26])
    {
        cout << w << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if(root->child[i])
        {
            w = w + (char)('a' + i);
            printEngDict(root->child[i], w);
            w.erase(w.size()-1,1);
        }
    }
}
bool find(EngDict* root, string w)
{
    EngDict* p = root;
    for(char c:w)
    {
        int j = c - 'a';
        if(p->child[j])
        {
            p = p->child[j];
        }
        else
            return false;
    }
    return p->child[26]!=nullptr;
}
//Cho biết chiều cao của cây từ điển nạp vào là bao nhiêu?
int height(EngDict* root)
{
    if (!root)
        return 0;

    int maxH = 0;
    for (int i = 0; i < 27; i++)
    {
        int h = height(root->child[i]);
        if (h > maxH)
            maxH = h;
    }
    return maxH + 1;
}
//Cây có bao nhiêu từ?
int count(EngDict* root)
{
    if(!root)
        return 0;
    else
    {
        int dem = 0;
        EngDict* p = root;
        if(p->child[26])
        {
            dem++;
        }
        for(int i = 0; i < 26; i++)
        {

            dem += count(root->child[i]);
        }
        return dem;
    }
}
//Nút có ít nút con nhất là bao nhiêu 
// bool isLa(EngDict* root)
// {
//     int count = 0;
//     for (int i = 0; i < 26; i++)
//     {
//         if(root->child[i])
//             count++;
//     }
// }
int minChild(EngDict* root, int min)
{
    if(!root)
        return 0;
    else
    {
        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if (root->child[i]) 
            {
                count++;  
            }
        }
        if (count > 0 && count < min) 
            min = count;
        for (int i = 0; i < 26; i++) 
        {
            if (root->child[i]) 
            {
                min = minChild(root->child[i], min);  
            }
        }
        return min;
    }
}
//Liệt kê tất cả những từ bắt đầu là xâu s.
void printDicS(EngDict* root, string s)
{
    if(root)
    {
        EngDict* p = root;
        string last = "";
        for(char c: s)
        {
            int i = c - 'a';
            p = p->child[i];
            last += c;
        }
        if(p)
        {
            printEngDict(p, last);

        }
        else
        {
            cout << "Khong co tu bat dau bang " << s << endl;
        }
    }
}
//Liệt kê những từ dài nhất trong từ điển.
void printLongestDic(EngDict* root)
{
    
}
int main()
{
    EngDict *root;int k; string w="";
    root = initDict();
    k = readDictFromFile("data.txt", root);
    cout << "List Dict" << endl;
    printEngDict(root, w);
    string inp;
    fflush(stdin);
    cout << "Input Word: "; cin >> inp;
    bool b = find(root, inp);
    if (b)
        cout << "found the word" << endl;
    else
        cout << "not found" << endl;
    cout << height(root) <<endl;
    cout << count(root) << endl;
    cout << minChild(root, 27) << endl;
    cout << "Input Word: "; cin >> inp;
    printDicS(root, inp);

}