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
	
	printStudent(goodStudent(ds));
}


