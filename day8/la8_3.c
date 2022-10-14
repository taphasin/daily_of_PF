#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
COORD star[scount];

struct star{
    int X;
    int Y;
    };
struct star s[21];

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void clear_buffer()
{	
	int y, x;
	for (y = 0; y < screen_y; ++y) {
		for (x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 0;
		}
	}
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}

void init_star()
{
	int i;
	for (i = 0; i < 20; ++i) {
		int sx = (rand() % 80);
		int sy = (rand() % 25);
		s[i].X = sx;
		s[i].Y = sy;
	}
}

void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		if (s[i].Y >= screen_y-1) {
			s[i].X = (rand() % screen_x);
			s[i].Y = 1;
		}
		else {
			//s[i].X = s[i].X;
			s[i].Y = s[i].Y+1;
		}
	}
}

void fill_star_to_buffer()
{
	int i;
	for (i = 0; i < 20; ++i){
		consoleBuffer[s[i].X + screen_x * s[i].Y].Char.AsciiChar = '*';
		consoleBuffer[s[i].X + screen_x * s[i].Y].Attributes = 7;
	}
}

int main()
{
	int i;
	srand(time(NULL));
	setConsole(screen_x, screen_y);
	init_star();
	i = 0;
	while (i < 1000)
	{
		star_fall();
		clear_buffer();
		fill_star_to_buffer();
		fill_buffer_to_console();
		Sleep(200);
		i++;
	}
	return 0;
}
