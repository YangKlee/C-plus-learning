#include <bits/stdc++.h>
using namespace std;
struct Student {
    std::string name;
    int age;
    float gpa;
};

struct CompareGPA {
    bool operator()(const Student& a, const Student& b) {
        return a.gpa > b.gpa; 
    }
};
struct CompareAge {
    bool operator()(const Student& a, const Student& b) {
        return a.age < b.age;
    }
};
struct CompareName {
    bool operator()(const Student& a, const Student& b) {
        return a.name > b.name; 
    }
};
int main() {
    // Priority Queue theo GPA tăng dần
    std::priority_queue<Student, std::vector<Student>, CompareGPA> pqGPA;
    // Priority Queue theo tuổi giảm dần
    std::priority_queue<Student, std::vector<Student>, CompareAge> pqAge;
    // Priority Queue theo tên tăng dần
    std::priority_queue<Student, std::vector<Student>, CompareName> pqName;

    Student s1 = {"Alice", 20, 3.8f};
    Student s2 = {"Bob", 22, 3.5f};
    Student s3 = {"Charlie", 21, 4.0f};

    // Thêm vào cả 3 priority_queue
    pqGPA.push(s1);
    pqGPA.push(s2);
    pqGPA.push(s3);

    pqAge.push(s1);
    pqAge.push(s2);
    pqAge.push(s3);

    pqName.push(s1);
    pqName.push(s2);
    pqName.push(s3);

    cout << "Priority Queue theo GPA tang dan:\n";
    while (!pqGPA.empty()) {
        Student top = pqGPA.top();
        cout << top.name << " " << top.age << " " << top.gpa << std::endl;
        pqGPA.pop();
    }
    cout << "\nPriority Queue theo tuoi giam dan:\n";
    while (!pqAge.empty()) {
        Student top = pqAge.top();
        cout << top.name << " " << top.age << " " << top.gpa << std::endl;
        pqAge.pop();
    }
    cout << "\nPriority Queue theo ten tang dan:\n";
    while (!pqName.empty()) {
        Student top = pqName.top();
        cout << top.name << " " << top.age << " " << top.gpa << std::endl;
        pqName.pop();
    }

    return 0;
}