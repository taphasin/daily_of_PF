//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

/*int mainop()
{
    FILE* fp;
    int a, b, c;
    fp = fopen("for stru.txt", "a");
    fprintf(fp, "%d %d %d\n", 11, 200, 500);
    return 0;
} */

int main()
{
    int i, lv, sc;
    char name[50];
    FILE* fp;
    int a, b, c;
    struct player {
        char name[50];
        int level;
        int score;
    };

    //fp = fopen("for stru.txt", "a");
    struct player p[10];

    for (int i = 0;i < 2;i++){
        printf("name :");
        scanf("%s", name);
        printf("lv :");
        scanf("%d", &lv);
        printf("sc :");
        scanf("%d", &sc);
        strcpy(p[i].name, name);
        p[i].level = lv;
        p[i].score = sc;
        fp = fopen("for stru.txt", "a");
        fprintf(fp, "%s %d %d\n", p[i].name, p[i].level, p[i].score);
        fclose(fp);
    }

    //fclose(fp);

    return 0;

}