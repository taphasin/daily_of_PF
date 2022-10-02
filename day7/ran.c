#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

int main()
{
	int i;
	srand( time( NULL ) );
	for (i=0;i<10;i++){
		printf("%d\n",(rand() % 5) + 1);
		Sleep(1000);
	}
	return 0;
}