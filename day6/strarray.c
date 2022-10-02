#include <stdio.h>
#include <string.h>

int main()
{
    char l[50], *p;
    scanf("%s", l);
    p = l;
    for(int i = 0; *(p+i) != '\0'; i++){
        if (l[i] >= 'a' && l[i] <= 'z')
        {
            printf("%c", *(p+i) - 32);
        }
        else if(l[i] >= 'A' && l[i] <= 'Z')
        {
            printf("%c", *(p+i) + 32);
        }
    } 
    return 0;
}