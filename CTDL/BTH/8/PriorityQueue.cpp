#include <bits/stdc++.h>
#define max 100
using namespace std;
struct Element{
    char data;
    int priority;

};
struct PriorityQueue
{
    Element arr[max];
    int size;
};
void siftUp(PriorityQueue *q)
{
    int i,p; Element tmp;
    i = q->size-1;
    while(i > 0)
    {
        p = (i-1)/2;
        if (q->arr[p].priority < q->arr[i].priority)
        {
            tmp = q->arr[p];
            q->arr[p] = q->arr[i];
            q->arr[i] = tmp;
            i = p;
        }
        else
            return;
    }
}
void add(PriorityQueue *q, Element x)
{
    q->arr[q->size] = x;
    q->size++;
    siftUp(q);
}
void siftDown(PriorityQueue *q)
{
    int p = 0, i = 2*p + 1;
    while (i < q->size)
    {
        if (i+1 <q->size && q->arr[i].priority<q->arr[i+1].priority)
            i = i + 1;
        if(q->arr[p].priority < q->arr[i].priority)
        {
            Element tmp = q->arr[p];
            q->arr[p] = q->arr[i];
            q->arr[i] = tmp;
            p = i;
            i = 2*p + 1;
        }
        else
            return;
    }
}
Element remove(PriorityQueue *q)
{
    int n; Element x;
    n = q->size;
    x = q->arr[0];
    q->arr[0] = q->arr[n-1];
    q->size--;
    siftDown(q);
    return x;
}
// Kiểm tra một hàng đợi ưu tiên có rỗng không
bool isEmpty(PriorityQueue q)
{
    return q.size == 0;
}

// Trả về phần tử đầu tiên của hàng đợi ưu tiên, không lấy ra khỏi hàng đợi
Element top(PriorityQueue q)
{
    if (!isEmpty(q))
        return q.arr[0];
    else
    {
        Element e = {'\0', -1}; 
        return e;
    }
}
int main()
{
    PriorityQueue q; Element x;
    q.size = 0;
    add(&q, {'A', 3});
    add(&q, {'B', 4});
    add(&q, {'C', 1});
    x = remove(&q);
    cout << x.data << " " << x.priority << endl;
    x = remove(&q);
    cout << x.data << " " << x.priority << endl;
    cout << isEmpty(q) << endl;
    cout << top(q).data << endl;
}