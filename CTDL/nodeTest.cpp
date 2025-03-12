#include <bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int age;
    double gpa;
};
struct NodeStudent
{
    Student data;
    NodeStudent *next;
};
void insert(NodeStudent* &p, Student std);
void inilazie(NodeStudent* &head);
void deleteStudent(NodeStudent* &p);
///typedef NodeStudent* Node;
NodeStudent* readfile(){
    NodeStudent* rawData = new NodeStudent;
    inilazie(rawData);
    ifstream file("studentdata.txt");
    string lineData, age, gpa;
    while (getline(file, lineData))
    {
        Student stInp;
        stringstream ss(lineData);
        getline(ss, stInp.name, ',');
        getline(ss, age, ',');
        getline(ss, gpa, ',');
        stInp.age = stoi(age);
        stInp.gpa = stod(gpa);
        insert(rawData, stInp );
    }
    return rawData;
}
void inilazie(NodeStudent* &head)
{
    head = nullptr;
}
void insert(NodeStudent* &p, Student std)
{
    NodeStudent *q = new NodeStudent;
    q->data = std;
    if (p == nullptr) // chua phan tu nao
    {
        q->next = p;
        p = q;  
    }
    else
    {
        q->next = p->next;
        p->next = q;
    }
    //cout << "Insert complete" << endl;
}
void getSinhVienGioi(NodeStudent* &p)
{
    while (p != nullptr)
    {
        NodeStudent *prev = p;
        NodeStudent *q = p->next;
        if (q->data.gpa <= 5)
        {
            deleteStudent(p);
        }
        //q = p->next;
        p = prev->next;
    }
}
void deleteStudent(NodeStudent* &p)
{
    if (p == nullptr)
    {
        cout << "Khong the xoa" << endl;
        return;
    }
    else
    {
        NodeStudent *q = p->next;
        p->next = q ->next;
        delete q;
    }
}
void showInfoStudent(Student data)
{
    cout << data.name << " " << data.age << " " << data.gpa << endl;
}
void duyetNode(NodeStudent* p)
{

    while (p != nullptr)
    {
        showInfoStudent(p->data);
        p = p->next;
    }
    
}
int coutOfStudent(NodeStudent* p)
{
    int count = 0;
    while(p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}
int main()
{
    NodeStudent *st = new NodeStudent ;
    inilazie(st);
    st = readfile();
    getSinhVienGioi(st);
    duyetNode(st);
    cout << "So luong hoc sinh la: " << coutOfStudent(st) << endl;

}