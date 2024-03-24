#include<stdio.h>

int main()
{
	int n = 5;
    int *k = &n;
    *k = *k+1;
    int *x = &k;
    x = x+1;
    printf("%d", n);

}