#include <bits\stdc++.h>
using namespace std;
int InterestingQuiz(int a, int b)
{
    int k = log2((float)b)/log2((float)a);
    while(pow(a,k) <= b)
    {
        k++;
    }
    return k;
}
int main()
{
    cout << InterestingQuiz(3,3520);
}