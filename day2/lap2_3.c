#include <stdio.h>

int main()
{
    int inp;
    printf("Input numbe : ");
    scanf("%d", &inp);
    for (int i = 1; i <= inp; i++)
    {
        for (int x = 1; (2*inp - 1) >= x; x++)
        {
            if (i >= x || x >= (2*inp) - i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = (inp - 1); i >= 1; i--)
    {
        for (int x = 1; (2*inp - 1) >= x; x++)
        {
            if (i >= x || x >= (2*inp) - i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}