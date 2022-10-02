#include <stdio.h>
int swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return 0;
}

int main()
{
    int a, b;
    printf("input : ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}