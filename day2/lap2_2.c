#include <stdio.h>
 
int main(void)
{
    int a, c = 0;
    printf("input : ");
    scanf("%d", &a);
    do
    {
        while(a > 0)
        {
        c = c + (a % 10);
        a = a / 10;
        }
        a = c;
        c = 0;
    }
    while (a > 9);
    printf("sum = %d", a);
    return 0;
}
