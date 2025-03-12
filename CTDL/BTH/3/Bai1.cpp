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
    ifstream fin("inp.txt");
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
        ss.clear();
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
bool isContainNumberPhone(Customer c, string phone)
{
    for (string number : c.phoneNumbers)
    {
        if (number == phone)
            return true;
    }
    return false;
}
int findContainCustomer(ListOfCustomers list, Customer c)
{
    for (int i = 0; i < list.numOfCustomers; i++)
    {
        if (list.arrCustomers[i].name == c.name && list.arrCustomers[i].address == c.address)
        {
            return i;
        }
    }
    return -1;
}
// Tìm khách hàng theo số điện thoại
int findCustomerByPhone(ListOfCustomers list, string phone)
{
    for (int i = 0; i < list.numOfCustomers ; i++)
    {
        if (isContainNumberPhone(list.arrCustomers[i], phone))
        {
            return i;
        }
    }
    return -1;
}
//hàm xóa một số điện thoại cụ thể của khách hàng trong danh sách.
void deletePhone(ListOfCustomers &list, string phone)
{
    for (int i = 0; i < list.numOfCustomers; i++)
    {
        for (int k = 0; k < list.arrCustomers[i].phoneNumbers.size(); k++)
        {
            if (list.arrCustomers[i].phoneNumbers[k] == phone)
            {
                list.arrCustomers[i].phoneNumbers.erase(list.arrCustomers[i].phoneNumbers.begin() + k);
                return;
            }
        }
    }
}
//
void mergeCustomer(ListOfCustomers &list, Customer c)
{
    int index = findContainCustomer(list, c);
    if (index != -1 )
    {
        for (int k = 0; k < c.phoneNumbers.size(); k++)
        {
            if (!isContainNumberPhone(list.arrCustomers[index], c.phoneNumbers[k]))
            {
                list.arrCustomers[index].phoneNumbers.pb(c.phoneNumbers[k]);
            }
        }
    }
    else
    {
        list.arrCustomers[list.numOfCustomers] = c;
        list.numOfCustomers += 1;
    }
}
int main()
{
    ListOfCustomers listCus;
    //inputListOfCustomers(listCus);
    inputListOfCustomerFromFile(listCus);
    //outputListOfCustomers(listCus);
    //deleteCustomerByName(listCus, "Nam");
    Customer test;
    test.name = "Nguyen Yen Nhi";
    test.address = "Tuy Phuoc, Binh Dinh";
    test.phoneNumbers.push_back("1234");
    mergeCustomer(listCus, test);
    outputListOfCustomers(listCus);

}
