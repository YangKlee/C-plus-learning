#include <bits/stdc++.h>
#include <math.h>
#define nullptr NULL
using namespace std;
struct Node{
    int coefficient;
    int exponent;
    Node* next;
};
//Hàm thêm một hạng tử vào đầu đa thức
void insertFirst(Node* &head, int coef, int expo) {
    Node* newP =  new Node;
    newP->coefficient = coef;
    newP->exponent = expo;
    newP->next = head;
    head = newP;
    //cout << "Insert complete" << endl;
}
//Hàm in một đa thức lên màn hình
void print(Node* head) {

    bool isFirst = true;
    while (head != nullptr)
    {
        if (head->coefficient >= 0)
        {
            if (isFirst){
                cout << head->coefficient;
                isFirst = false;
            }
            else{
                cout << " + " << head->coefficient;
            }
        }
        else
            cout << "-" << abs(head->coefficient);
        cout << "x^";
        if (head->exponent < 0)
            cout << "(" << "-" << abs(head->exponent) << ")";
        else
            cout << head->exponent;
        head = head->next;
    }
    cout << endl;
    return;
}
//Tính giá trị đa thức P(x)
double evaluate(Node* head, double x) {
    double result = 0;
    while (head != nullptr)
    {
        result += ((float)head->coefficient *powf(x,head->exponent));
        head = head->next;
    }
    return result;
}

Node* insertNext(Node* node, int coef, int expo) {
    Node* newNode = new Node;
    newNode->coefficient = coef;
    newNode->exponent = expo;
    newNode->next = NULL;
    if (node) node->next = newNode;
    return newNode;
    }
//Hàm cộng hai đa thức:
Node* add(Node* poly1, Node* poly2) {
    Node *result = NULL, *last = NULL, *temp;
    while (poly1 && poly2) {
    if (poly1->exponent > poly2->exponent) {
    last = insertNext(last, poly1->coefficient,poly1->exponent);
    poly1 = poly1->next;
    }
    else if (poly2->exponent > poly1->exponent) {
    last=insertNext(last,poly2->coefficient,poly2->exponent);
    poly2 = poly2->next;
    }
    else {
    int coef = poly1->coefficient + poly2->coefficient;
    if (coef != 0)
    last = insertNext(last, coef, poly1->exponent);
    poly1 = poly1->next;
    poly2 = poly2->next;
    }
        if (!result)
        result = last;
        }
    while (poly1) {
        last = insertNext(last, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
        }
        while (poly2) {
        last = insertNext(last, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
        }
        return result;
}
bool isContainExp(Node* head,int coef, int exp)
{
    while(head != nullptr)
    {
        if (head->exponent == exp)
        {
            head->coefficient += coef;
            return true;
        }
        head = head->next;
    }
    return false;
}
void softExp(Node* res)
{
    while (res != nullptr)
    {
        
        res = res->next;
    }
}
Node* nhanDaThuc(Node* poly1 , Node* poly2){
    Node* result = nullptr;
    Node* last = nullptr;
    while(poly1 != nullptr)
    {
        Node* j = poly2;
        while(j != nullptr)
        {
            //cout <<poly1->coefficient << " *" << j->coefficient << endl;
            int kq_coef = poly1->coefficient * j->coefficient;
            int kq_exp  = poly1->exponent + j->exponent;
            if (kq_coef != 0)
            {
                if (!isContainExp(result,kq_coef , kq_exp))
                {
                    last = insertNext(last, kq_coef, kq_exp);
                }
            }
            if (!result)
                result = last;
            j = j->next;
        }
        poly1 = poly1->next;
    }
    return result;
}
// Dao ham
Node* derivative(Node* poly) {
    Node* result = nullptr;
    Node* last = nullptr;
    while (poly != nullptr)
    {
        if (poly->exponent > 0)
        {
            last = insertNext(last, poly->coefficient * poly->exponent, poly->exponent - 1);
        }
        if (result == nullptr)
            result = last;
        poly = poly->next;
    }
    return result;
}
int main()
{
    Node* p1 = nullptr ;
    insertFirst(p1, 10,5);
    insertFirst(p1, 5,3);
    insertFirst(p1, 4,2);
    insertFirst(p1, 2,1);

    Node* p2 = nullptr ;
    insertFirst(p2, 3,4);
    insertFirst(p2, 2,2);
    insertFirst(p2, 2,1);
    cout << "p1 = ";
    print(p1);
    cout << "p2 = ";
    print(p2);
    cout << "Dao ham da thuc p1: ";
    print(derivative(p1));
    cout << "Phep nhan da thuc p1 * p2:";
    print(nhanDaThuc(p1, p2));

}
