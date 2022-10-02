#include <stdio.h>

int main()
{
    int num, mid = 1;
    printf("Enter number : ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        if (mid == 1 || mid == num)
        {
            for (int e = 1; e <= num; e++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            for (int m = 1; m <= num; m++)
            {
                if (m == 1 || m == num)
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
        mid++;
    }
}