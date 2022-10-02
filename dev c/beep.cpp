#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void draw_star(int x, int y)
{
 COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    printf("*");
}

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
	int i, sx, sy;
	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		sy = (rand() % 4) + 2;
		sx = (rand() % 61) + 10;
		draw_star(sx,sy);
		Sleep(1000);
	}
	return 0;
}
