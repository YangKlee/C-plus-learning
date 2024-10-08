#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        result[i] = A[(i + (k % n)) % n];
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
