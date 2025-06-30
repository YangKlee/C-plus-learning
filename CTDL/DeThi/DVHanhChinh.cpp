#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    string name;
    TreeNode *child, *sib;
};
void createTree(TreeNode *&root)
{
    TreeNode* h23 = new TreeNode{"TP Thu Duc", nullptr, nullptr};
    TreeNode* h22 = new TreeNode{"Quan Binh Thanh", nullptr, h23};
    TreeNode* h21 = new TreeNode{"Quan Mot", nullptr, h22};
    TreeNode* h14 = new TreeNode{"TP HCM", h21, nullptr};
    TreeNode* h13 = new TreeNode{"TP Ha Noi", nullptr, h14};
    TreeNode* h12 = new TreeNode{"TP Da Nang", nullptr, h13};
    TreeNode* h11 = new TreeNode{"Tinh Binh Dinh", nullptr, h12};
    root = new TreeNode{"Dat nuoc VietNam", h11, nullptr};
}
void DFS(TreeNode *root)
{
    if(root)
    {
        cout << root->name << endl;
        DFS(root->child);
        DFS(root->sib);
    }
}
void isMostSib(TreeNode* root, int &max, TreeNode*& maxNode)
{
    if(root)
    {
        queue<TreeNode*> q;
        // đẩy tất cả các tỉnh thành phố vào queue
        root = root->child;
        while (root)
        {
            q.push(root);  root = root->sib;
        }
        // xét từng thằng trong queue
        while(!q.empty())
        {
            TreeNode *p = q.front(); q.pop();
            // nếu thằng p mà nó có con thì cho con nó vô q và đếm số con
            if(p->child)
            {
                TreeNode *childP = p->child;
                int count = 0;
                while(childP)
                {
                    count++; q.push(childP); childP = childP->sib;
                }
                if(count > max)
                {
                    max = count; maxNode = p;
                }
            }

        }
      
    }
}
int getMaxLevel(TreeNode* root, int level = 0)
{
    if (!root) return level - 1;

    int maxChild = getMaxLevel(root->child, level + 1);
    int maxSib = getMaxLevel(root->sib, level);

    return max(maxChild, maxSib);
}
// xác định bậc của 1 tỉnh/thành/xã
int getBacX(TreeNode* root, string name, int bac)
{
    if(!root)
        return -1;
    else
    {
        if(root->name == name)
            return bac;
        int bacChild = getBacX(root->child, name, bac+1);
        if(bacChild != -1) return bacChild;
        else
            return getBacX(root->sib, name, bac);
    }
}
// xóa 1 tỉnh thành 
void deleteNode(TreeNode* &root, string name)
{
    if(root)
    {
        TreeNode *x = nullptr;
        // tìm node cần xóa
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p = q.front(); q.pop();
            if(p->child) // nếu p có con
            {
                TreeNode* k = p->child;
                while(k)
                {
                    if(k->name == name)
                    {
                        // gán nốt cha
                        x = p;
                    }
                    q.push(k);
                    k = k->sib;
                }
            }

        }
        if (x)
        {
             TreeNode *deleteNode = x->child;
            // th1: nút cần xóa nối trực tiếp vs node cha
            if(deleteNode->name == name)
            {
                // liên kết con trỏ x child tới node khác sau node cần xóa
               
                x->child = deleteNode->sib;
                delete(deleteNode);
            }
            // th2: nút cần xóa không nối vs node cha
            // tìm nút cần xóa
            else
            {
                TreeNode *parentDeleteNode = deleteNode;
                deleteNode = deleteNode->sib;
                while(deleteNode)
                {
                    if(deleteNode->name == name)
                        break;
                    deleteNode = deleteNode->sib;
                    parentDeleteNode = parentDeleteNode->sib;
                }
                // đổi địa chỉ 
                parentDeleteNode->sib = deleteNode->sib;
                delete(deleteNode);
            }
            
        }
    }

}
int main()
{
    TreeNode* root;
    createTree(root);
    DFS(root);
    // kiểm tra thành phố/ tỉnh có nhiều đơn vị hành chính trực thuộc nhất
    TreeNode *p = nullptr;
    int maxTrucThuoc = 0;
    isMostSib(root, maxTrucThuoc, p);
        
    if (p != nullptr)
        cout << "Thanh pho co nhieu nhat la" << p->name << " voi so luong la" << maxTrucThuoc << endl;

}