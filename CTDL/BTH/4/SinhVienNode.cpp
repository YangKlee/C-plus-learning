#include <bits/stdc++.h>
#define nullptr NULL
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct SinhVien{
	string HoTen;
	float dtb;
};
struct NodeSinhVien{
	SinhVien data;
	NodeSinhVien *next;
};
typedef NodeSinhVien* Node;

int main()
{
	IOS;
	Node dsSV = nullptr;
	SinhVien sv;
	sv.dtb = 1;
	sv.HoTen = "Shikanoko";
	insert(dsSV, sv);
	cout << coutOfSinhVien(dsSV);
	
}


