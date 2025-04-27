#include <bits/stdc++.h>
#include <ctime>
using namespace std;
struct Student
{
    string name;
    float gpa;
};

void siftDown(Student arr[], int i, int n)
{
    int maxIndex = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && arr[left].gpa < arr[maxIndex].gpa)
        maxIndex = left;
    if (right < n && arr[right].gpa < arr[maxIndex].gpa)
        maxIndex = right;
    if (i != maxIndex)
    {
        swap(arr[i], arr[maxIndex]);
        siftDown(arr, maxIndex, n);
    }
}
void heapSort(Student arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    siftDown(arr, i, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        siftDown(arr, 0, i);
    }
}
void randomArr(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        a[i] = rand();
}
// Driver code
int main()
{
    int n = 10;
    Student arr[1000] = {
        {"An", 3.56},
        {"Binh", 2.78},
        {"Chi", 3.91},
        {"Duc", 1.85},
        {"Hoa", 2.43},
        {"Khanh", 3.12},
        {"Linh", 2.97},
        {"Minh", 3.45},
        {"Nam", 1.64},
        {"Trang", 3.88}
    };
    heapSort(arr, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
    cout << arr[i].name << " " << arr[i].gpa << " ";
    return 0;
}
