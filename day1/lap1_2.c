#include <stdio.h>

int main()
{
    int f, s, h, l;
    printf("Enter first number : ");
    scanf("%d", &f);
    printf("Enter second number : ");
    scanf("%d", &s);
    if (f > s)
    {
        h = f;
        l = s;
    }
    else if (s > f)
    {
        h = s;
        l = f;
    }
    for (int i = l; h % i != 0 || l % i != 0 ; i--)
    {
        s = i - 1;
    }
    printf("Greatest common divisor = %d", s);

}