#include <windows.h>
#include<stdio.h>
#include<string.h>
#define screen_x 80
#define screen_y 25

CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
HANDLE wHnd;

struct star{
    int spx;
    int spy;
    };
struct star s[21];

void star_fall(){
	
}

//void star_

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void fill_data_to_buffer()
{
	for (int i = 0; i < 20; ++i) {
		int x = (rand() % 80);
		int y = (rand() % 25);
		s[i].spx = x;
		s[i].spy = y;
		consoleBuffer[x + screen_x * y].Char.AsciiChar = '*';
		consoleBuffer[x + screen_x * y].Attributes = 7;
	}
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}

int main()
{
	struct star{
    	int spx;
    	int spy;
    };
	setConsole(screen_x, screen_y);
	fill_data_to_buffer();
	fill_buffer_to_console();
	Sleep(5000);
//	do {
	
//	} while (ch!='x');
	return 0;
}
