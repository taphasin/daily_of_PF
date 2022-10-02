#include <stdio.h>

int main()
{
    int i, y;
    for(i = 1; i <= 10000; i++)
    {
        int x = 0;
        for(y = 1; y < i; y++)
        {
            if (i % y == 0)
            {
                x = x + y;
            }
        }
        if (x == i)
        {
            printf("%d ", x);
        }

    }
    return 0;
}