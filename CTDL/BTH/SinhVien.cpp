#include <bits/stdc++.h>
#include <string>
#include <sstream>
#define nullptr NULL
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct Student{
	string name;
	int age;
	double gpa;

};
struct SLLStudents{
	Student data;
	SLLStudents *next;
};
typedef SLLStudents Node;
Node* insertLast(Node* p, Student st)
{
	Node* newSt = new Node;
	newSt->data = st;
	if (p != nullptr)
		p->next = newSt;
	return newSt;
}
Node* readFile(const string filename)
{
	Node* result = nullptr;
	Node* last = nullptr;
	ifstream inFile(filename.c_str());
	Student tmp;
	string age, gpa;
	while (getline(inFile, tmp.name, ',') && getline(inFile, age, ',') && getline(inFile, gpa))
	{
		tmp.age = stoi(age);
		tmp.gpa = stod(gpa);
		last = insertLast(last, tmp);
		if (result == nullptr)
			result = last;
	}
	return result;
}
// T?o danh sách nh?ng sinh viên ch?a nh?ng sinh viên có gpa >= 8 
Node* goodStudent(Node* head)
{
	Node* result = nullptr;
	Node* last = nullptr;
	while (head != nullptr)
	{
		if (head->data.gpa >= 8)
			last = insertLast(last, head->data);
		if (result == nullptr && last != nullptr)
			result = last;
		head = head->next;
	}
	return result;
}
Node* findByName(Node *head, string name)
{
	while (head != nullptr)
	{
		if (head->data.name == name)
			return head;
		head = head->next;
	}
	
}
void deleteByName(Node* &head, string name)
{
	// phan tu can xoa nam dau tien
	if (head->data.name == name)
	{
		head = head->next;
		
	}
	else
	{
		Node* tmp = head->next;
		Node* last = head;
		while(tmp!= nullptr)
		{
			if (tmp->data.name == name)
			{
				
				last->next = tmp->next;
				delete tmp;
			}
			tmp = tmp->next;
			last = last->next;
		}
	}

}
// them sinh vien vao vi tri k (k so nguyen)
void insertK(Node* &head, Student st, int k)
{
	Node* newSt = new Node();
	newSt->data = st;
	if (k == 1) // dau
	{
		newSt->next = head;
		head = newSt;
	}
	else
	{
		int count = 1;
		Node* tmp = head;
		while (tmp!=nullptr)
		{
			if (count == k)
			{
				newSt->next = tmp->next;
				tmp->next = newSt;
				return;
			}
			count++;
			tmp = tmp->next;
		}
	}
}
void deleteK(Node* &head, int k)
{
	if (k == 1)
	{
		head = head->next;
	}
	else
	{
		Node* tmp = head->next;
		Node* last = head;
		int count = 2;
		while (tmp != nullptr)
		{
			if (count == k)
			{
				last->next = tmp->next;
				delete tmp;
				return;
			}
			count++;
			tmp = tmp->next;
			last = last->next;
		}
	}
}
void printStudent(Node* head)
{
	while (head != nullptr )
	{
		cout << head->data.name << "," << head->data.age << "," << head->data.gpa << endl;
		head = head->next;
	}
}
int main()
{
	
	Node* ds = readFile("studentdata.txt");
	
	//deleteByName(ds, "Nguyen Van C");
	Student newSt ;
	newSt.name = "Shikanoko";
	newSt.gpa = 2.2;
	newSt.age = 16;
	insertK(ds, newSt, 9);
	deleteK(ds, 10);
	printStudent(ds);
}


