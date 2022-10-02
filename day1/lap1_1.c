#include <stdio.h>

int main()
{
    int num;
    int op = 1;
    printf("Enter number : ");
    scanf("%d", &num);
    printf("Factoring Result : ");
    for(int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            if (op != 1)
            {
                printf(" x ");
            }
            op++;
            printf("%d", i);
            num = num / i;
        }
    }
}