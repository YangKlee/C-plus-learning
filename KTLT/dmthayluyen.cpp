#include <bits/stdc++.h>
using namespace std;

void dayA(vector<int>& A) {
    vector<int> duong, am;
    for (int num : A) {
        if (num >= 0) {
            duong.push_back(num);
        } else {
            am.push_back(num);
        }
    }
   
    A.clear();
    int posSize = duong.size(), negSize = am.size();
    int i = 0, j = 0;
   
    while (i < posSize && j < negSize) {
        A.push_back(duong[i++]);
        A.push_back(am[j++]);
    }
   
    while (i < posSize) {
        A.push_back(duong[i++]);
    }
   
    while (j < negSize) {
        A.push_back(am[j++]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
   
    dayA(A);
   
    for (int num : A) {
        cout << num << " ";
    }
    return 0;
}
