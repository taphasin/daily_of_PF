#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

char cursor(int x, int y){
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = {x,y}; DWORD num_read;
	if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) ){
		return '\0';
	}
	else{
		return buf[0];
	}
}

int main()
{
    char x;
    printf("abcd");
    x = cursor(0,0);
    if (x == 'a'){
    	printf("\n%c", x);
	}
    return 0;
}
