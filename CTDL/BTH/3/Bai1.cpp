#include <bits/stdc++.h>
#define MAX 100
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using namespace std;
struct Customer
{
    string name;
    string address;
    vector <string> phoneNumbers;
};
struct ListOfCustomers
{
    Customer arrCustomers[MAX];
    int numOfCustomers;
};
void inputCustomer(Customer &c)
{
    fflush(stdin);
    cin.ignore();
    cout << "Nhap ten khach hang: "; getline(cin, c.name);
    cout << "Nhap dia chi: "; getline(cin, c.address);
    int numOfPhone = 0;
    cout << "Nhap so luong so dien thoai: " ; cin >> numOfPhone;
    for (int i = 0; i < numOfPhone; i++)
    {
        string phone;
        cout << "So dien thoai: " ; cin >> phone;
        c.phoneNumbers.pb(phone);
    }
}
// nhap tu file
void inputListOfCustomerFromFile(ListOfCustomers &list)
{
    ifstream fin("customer.txt");
    string rawData;
    while (getline(fin, rawData))
    {
       Customer cs;
       stringstream ss(rawData);
       getline(ss, cs.name, ';');
       getline(ss, cs.address, ';');
       string phone;
       while (getline(ss, phone, ';'))
            cs.phoneNumbers.pb(phone);
        list.arrCustomers[list.numOfCustomers] = cs;
        list.numOfCustomers +=1;
    }
    fin.close();
}
//Output a customer
void outputCustomer(Customer c)
{
    cout << "========================" << endl;
    int i;
    cout << "Ten: " << c.name << endl;
    cout << "Dia chi: " << c.address << endl;
    cout << "Danh sach so dien thoai: "  << endl;
    for (i = 0; i < c.phoneNumbers.size(); i++)
    {
        cout << c.phoneNumbers[i] << " ";
        cout << endl;
    }
}
//Input a list of customers
void inputListOfCustomers(ListOfCustomers& list)
{
    cout << "Nhap so luong khach hang: "; cin >> list.numOfCustomers;
    for(int i = 0; i < list.numOfCustomers; i++)
        inputCustomer(list.arrCustomers[i]);
}
//Output a list of customers
void outputListOfCustomers(ListOfCustomers list)
{
    cout << "Number of customers: " << list.numOfCustomers << endl;
    for(int i = 0; i < list.numOfCustomers; i++)
        outputCustomer(list.arrCustomers[i]);
}
void deleteCustomer(ListOfCustomers &list, int index)
{
    for (int i = index; i < list.numOfCustomers; i++){
        list.arrCustomers[i] = list.arrCustomers[i+1];
    }
    list.numOfCustomers -= 1;
}
// Xóa một khách hàng theo tên
void deleteCustomerByName(ListOfCustomers &list, string name)
{
    for (int i = 0; i < list.numOfCustomers; i++)
    {
        if (list.arrCustomers[i].name == name)
        {
            deleteCustomer(list, i);
            return;
        }
    }
}
// Tìm khách hàng theo số điện thoại
int main()
{
    ListOfCustomers listCus;
    //inputListOfCustomers(listCus);
    inputListOfCustomerFromFile(listCus);
    outputListOfCustomers(listCus);
    deleteCustomerByName(listCus, "Nam");
    outputListOfCustomers(listCus);
}
