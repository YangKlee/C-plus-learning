#include <bits/stdc++.h>
#define nullptr NULL
using namespace std;
struct File{
    string name;
    int size;
};
struct Floder
{
    string name;
    vector<File> files;
    vector<Floder*> child;
};
// data/
// ├── database.db (1122 KB)
// ├── userdata.dat (300 KB)
// ├── images/
// │   ├── shikanoko.jpg (200 KB)
// │   ├── bashameme.jpg (200 KB)
// │   ├── koshi_anko.jpg (200 KB)
// │   └── koshitan.png (200 KB)
// ├── video/
// │   └── j97.mp4 (5000000 KB)
// └── assest/
//     ├── css/
//     │   ├── home.css (100 KB)
//     │   ├── header.css (100 KB)
//     │   └── footer.css (100 KB)
//     ├── js/
//     │   ├── home.js (20 KB)
//     │   └── index.js (20 KB)
//     └── pages/
//         ├── index.php (400 KB)
//         ├── login.php (100 KB)
//         └── module.php (400 KB)
Floder* createFloder()
{
    vector<File> fileSample;
    vector<Floder*> childSample;
    Floder *root, *f1, *f2, *f3, *f4, *f5, *f6;

    fileSample = {{"index.php", 400}, {"login.php", 100}, {"module.php", 400}};
    childSample = {};
    f6 = new Floder({"pages", fileSample, childSample});

    fileSample = {{"home.js", 20}, {"index.js", 20}};
    childSample = {};
    f5 = new Floder({"js", fileSample, childSample});

    fileSample = {{"home.css", 100}, {"header.css", 100}, {"footer.css", 100}};
    childSample = {};
    f4 = new Floder({"css", fileSample, childSample});

    fileSample = {};
    childSample = {f4, f5, f6};
    f3 = new Floder({"assest", fileSample, childSample});

    fileSample = {{"j97.mp4", 5000000}};
    childSample = {};
    f2 = new Floder({"video", fileSample, childSample});

    fileSample = {{"shikanoko.jpg", 200}, {"bashameme.jpg", 200}, {"koshi_anko.jpg", 200}, {"koshitan.png", 200}};
    childSample = {};
    f1 = new Floder({"images", fileSample, childSample});

    fileSample = {{"database.db", 1122}, {"userdata.dat", 300}};
    childSample = {f1, f2, f3};
    root = new Floder({"data", fileSample, childSample});

    return root;
}
//In cây thư mục.
void print(Floder* root, int level)
{
    if(root)
    {
        for(int i = 0; i < level; i++)
        {
            cout << "\t";
        }
        cout << root->name << "/" << endl;
        for (File f: root->files)
        {
            for(int i = 0; i <= level; i++)
            {
                cout << "\t";
            }
            cout << "-" << f.name << '(' << f.size << "KB" << ')' << endl;
        }
        for(Floder* f: root->child)
        {
            
            print(f, level+1);
        }   
    }
}
//Tìm một tập tin hay thư mục trong cây.
bool find(Floder* root, string name)
{
    if(!root)
        return false;
    else
    {
        if(root->name == name)
            return true;
        for(File f: root->files)
        {
            if(f.name == name)
                return true;
        }
        for(Floder* c:root->child)
        {
            bool child = find(c, name);
            if(child)
                return true;
        }
        return false;
    }
}
//Tính tổng kích thước các tập tin trong cây thư mục.
int size(Floder* root)
{
    if(!root)
        return 0;
    else
    {
        int sum = 0;
        for(File f:root->files)
        {
            sum+= f.size;
        }
        for(Floder* c:root->child)
        {
            sum += size(c);
        }
        return sum;
    }
}
// Liệt kê tất cả đường dẫn đến tập tin tên fileName trong cây thư mục
bool isContainFileFloder(Floder* root, string filename)
{
    for(File f:root->files)
    {
        if(f.name == filename)
            return true;
    }
    return false;
}
void getPath(Floder* root, string fileName, stack<string>&floder)
{
    if(root)
    { 
        bool f = isContainFileFloder(root, fileName);
        floder.push('/'+root->name);
        if(!f)
        {
            if(!root->child.size())
            {
                floder.pop();
            }
            for(Floder* c:root->child)
            {
                
                getPath(c, fileName, floder);

            }
        }
        else{
            floder.push('/'+fileName);
            vector<string> floderOutput;
            while(!floder.empty())
            {
                floderOutput.push_back(floder.top());
                floder.pop();
            }
            reverse(floderOutput.begin(), floderOutput.end());
            for(string s: floderOutput)
            {
                cout << s;
            }
            cout << endl;
            return;
        }

    }
}
//Xóa một tập tin trong cây thư mục
void deleteFile(Floder* root, string fileName)
{
    if(root)
    {
        for(int i = 0; i < root->files.size(); i++)
        {
            if(root->files[i].name == fileName)
            {
                root->files.erase(root->files.begin()+i);
                return;
            }

        }
        for(Floder* c:root->child)
        {
            deleteFile(c, fileName);
        }
    }
}
//Xóa một thư mục trong cây thư mục.
void deleteFloder(Floder* root, string floderName)
{
    if(root)
    {
        for(int i = 0; i < root->child.size(); i++)
        {
            if(root->child[i]->name == floderName)
            {
                
                root->child.erase(root->child.begin()+i);
                delete(root->child[i]);
                return;
            }
            else
            {
                deleteFloder(root->child[i], floderName);
            }

        }
    }
}
int main()
{
    Floder* root = createFloder();
    print(root, 0);
    if(find(root, "shikanoko.jpg"))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    cout << size(root) << endl;
    // Liệt kê tất cả đường dẫn đến tập tin tên fileName trong cây thư mục
    stack<string> floder;
    getPath(root, "module.php", floder);
    deleteFile(root,"module.php");
    print(root, 0);
    deleteFloder(root,"images");
    print(root, 0);

}