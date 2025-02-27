#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Student{
    string name;
    int age;
    double gpa;
};
// input a student
void inputStudent(struct Student &s)
{
    cout << "Name: " ; getline(cin, s.name);
    cout << "Age: "; cin >> s.age;
    cout << "GPA: "; cin >> s.gpa;
}
// print a student
void printStudent(struct Student s)
{
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;
}
// input an aray of student
void inputListOfStudent(struct Student list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        inputStudent(list[i]);
    }
}
// print an array of student
void printListOfStudent(struct Student list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printStudent(list[i]);
    }
}
// find a student by name
int findStudent(struct Student list[], int n, string name)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i].name == name)
            return i;
    }
    return -1;
}
// BO SUNG
// liet ke cac sinh vien co gpa >= 8
void listOfGoodStudents(struct Student list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i].gpa >= 8)
            printStudent(list[i]);
    }
}
// them mot sinh vien vao cuoi mang chua n sinh vien
int appdendStudent(struct Student list[], int n, struct Student s)
{
    list[n] = s;
    return n +1;
}
// Dem so nguoi ho Nguyen trong mang sinh vien
int countFirstName(struct Student list[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (list[i].name.substr(0, 6) == "Nguyen" || list[i].name.substr(0, 6) == "nguyen")
        {
            count++;
        }
    }
    return count;
}
// doi ten len dau
string convertName(string name)
{
    int i = 0;
    string ten = "";
    while (name[i] != ' ')
    {
        ten = name[i] + ten;
        name.erase(i);
    }
    return ten + " " + name;
}
// ham sap xep ten Tieng Viet
void sortVNName(struct Student list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n - 1; j++)
        {
            list[i].name = convertName(list[i].name);
            list[j].name = convertName(list[j].name);
            if (list[i].name[0] > list[j].name[0])
            {
                Student tmp = list[j];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}
int main()
{
    Student list[100];
    freopen("input.inp","r",stdin);
    int n; cin >> n;
    
    inputListOfStudent(list, n);
    printListOfStudent(list, n);
}