#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,max,min;
    cin >> a >> b >> c;
    if (max>c && c>min){
        cout << c << endl;
    }
    if(c>max){
        cout << max << endl;
    }else {
        cout << min << endl;
    }
    return  0;
}