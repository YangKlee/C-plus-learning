#include <bits/stdc++.h>
#define nullptr NULL
using namespace std;
struct colNode{ // node các cột
    int index;
    int value;
    colNode* next;
};
struct rowNode{ // node các dòng
    int index;
    colNode* col;
    rowNode* next;
};
rowNode* addRow(rowNode* r, colNode* c,int index)
{
    rowNode* newR = new rowNode;
    newR->index = index;
    newR->col = c;
    newR->next = nullptr;
    if (r != nullptr)
        r->next = newR;
    return newR;
}
colNode* addCol(colNode* c, int index, int value)
{
    colNode* newC = new colNode;
    newC->index = index;
    newC->value = value;
    newC->next =  nullptr;
    if (c != nullptr)
        c->next = newC;
    return newC;
}
// Chuyển đổi từ ma trận sang ma trận thưa
rowNode* convertMatrixThua(vector<vector<int>> a)
{
    rowNode* result_row = nullptr;
    rowNode* last_row = nullptr;
    for (int i = 0; i < a.size(); i++)
    {
        colNode* result_col = nullptr;
        colNode* last_col = nullptr;
        for (int j = 0; j < a[i].size(); j++)
        {
            //cout << a[i][j] << endl;
            if (a[i][j] != 0)
            {
                last_col = addCol(last_col, j, a[i][j]);
            }
                
            if (result_col == nullptr && last_col != nullptr)
                result_col = last_col;
        }
        last_row = addRow(last_row, result_col, i);
        
        if (result_row == nullptr)
            result_row = last_row;
    }
    return result_row;
}
// Chuyển đổi từ ma trận thưa sang ma trận
vector <vector<int>> convertMatrix(rowNode* m)
{
    cout << "Launch" << endl;
    vector<vector<int>> result;
    while (m != nullptr)
    {
        //cout << m->index << endl;
        vector <int> row;
        int last = 0;
        if (m->col != nullptr)
        {
            if (m->col->index != 0)
                row.push_back(0);
        }

        while(m->col != nullptr)
        {
            for (int i = 1; i <= (m->col->index - 1) - last; i++)
            {
                row.push_back(0);
            } 
            last = m->col->index;
            row.push_back(m->col->value); 
            m->col =  m->col->next;
        }
        result.push_back(row);
        m = m->next;
    }
    cout << "convert complete" << endl;
    // can bang ma tran
    int max_lenght = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i].size() > max_lenght)
            max_lenght = result[i].size();
    }
    for (int i = 0; i < result.size(); i++)
    {
        while (result[i].size() < max_lenght)
        {
            result[i].push_back(0);
        }
    }
    return result;
}
// cộng ma trận thưa
rowNode* sumMatrix(rowNode* a, rowNode* b)
{

    rowNode* result_row = nullptr, *last_row = nullptr;
    while (a != nullptr && b != nullptr)
    {
        colNode* result_col = nullptr, *last_col = nullptr;
        while (a->col != nullptr && b->col != nullptr)
        {
            if (a->col->index < b->col->index)
            {
                last_col = addCol(last_col, a->col->index, a->col->value) ;
                a->col = a->col->next;
            }
            else if (a->col->index > b->col->index)
            {
                last_col = addCol(last_col, b->col->index, b->col->value) ;
                b->col = b->col->next;
            }
            else
            {
                if (a->col->value + b->col->value != 0)
                {
                    //cout << a->col->value + b->col->value << endl;
                    last_col = addCol(last_col, b->col->index, a->col->value + b->col->value) ;
                }
                a->col = a->col->next;
                b->col = b->col->next;
            }
            if (result_col == nullptr && last_col != nullptr)
            {
                result_col = last_col;
            }

        }
        while (a->col != nullptr)
        {
            last_col = addCol(last_col, a->col->index, a->col->value);
            a->col = a->col->next;
            if (result_col == nullptr && last_col != nullptr)
            {
                result_col = last_col;
            }
        }
        while (b->col != nullptr)
        {
            last_col = addCol(last_col, b->col->index, b->col->value);
            b->col = b->col->next;
            if (result_col == nullptr && last_col != nullptr)
            {
                result_col = last_col;
            }
        }
        last_row = addRow(last_row, result_col, a->index);
        if (result_row == nullptr && last_row != nullptr)
        {
            result_row = last_row;
        }
        a = a->next;
        b = b->next;
    }
    return result_row;
}
// tru ma trận thưa
rowNode* desumMatrix(rowNode* a, rowNode* b)
{
    rowNode* result_row = nullptr, *last_row = nullptr;
    while (a != nullptr && b != nullptr)
    {
        colNode* result_col = nullptr, *last_col = nullptr;
        while (a->col != nullptr && b->col != nullptr)
        {
            if (a->col->index < b->col->index)
            {
                last_col = addCol(last_col, a->col->index, a->col->value) ;
                a->col = a->col->next;
            }
            else if (a->col->index > b->col->index)
            {
                last_col = addCol(last_col, b->col->index, -b->col->value) ;
                b->col = b->col->next;
            }
            else
            {
                if (a->col->value - b->col->value != 0)
                {
                    //cout << a->col->value + b->col->value << endl;
                    last_col = addCol(last_col, b->col->index, a->col->value - b->col->value) ;
                }
                a->col = a->col->next;
                b->col = b->col->next;
            }
            if (result_col == nullptr && last_col != nullptr)
            {
                result_col = last_col;
            }

        }
        while (a->col != nullptr)
        {
            last_col = addCol(last_col, a->col->index, a->col->value);
            a->col = a->col->next;
            if (result_col == nullptr && last_col != nullptr)
            {
                result_col = last_col;
            }
        }
        while (b->col != nullptr)
        {
            last_col = addCol(last_col, b->col->index, -b->col->value);
            b->col = b->col->next;
            if (result_col == nullptr && last_col != nullptr)
            {
                result_col = last_col;
            }
        }
        last_row = addRow(last_row, result_col, a->index);
        if (result_row == nullptr && last_row != nullptr)
        {
            result_row = last_row;
        }
        a = a->next;
        b = b->next;
    }
    return result_row;
}
void printMatrix(vector <vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    vector<vector<int>> a {{0,0,3,0}, {0,0,0,0}, {0, 0, -1,0}, {0,2,6,0}};
    vector<vector<int>> b {{1,0,3,0}, {1,0,5,7}, {0, 0, 1,2}, {0,2,6,0}};
    rowNode* MatA = convertMatrixThua(a);
    rowNode* MatB = convertMatrixThua(b);
    rowNode* resultSum = sumMatrix(MatA, MatB);
    MatA = convertMatrixThua(a);
    MatB = convertMatrixThua(b);
    rowNode* resultdeSum = desumMatrix(MatA, MatB);
    printMatrix(convertMatrix(resultSum));
    printMatrix(convertMatrix(resultdeSum));
}
