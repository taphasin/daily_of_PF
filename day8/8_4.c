#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#define screen_x 80
#define screen_y 25
#define scount 80

HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = { 0,0 };
DWORD numEvents = 0;
DWORD numEventsRead = 0;
INPUT_RECORD eventBuffer[2000];
COORD star[scount];
int colour = 7;

struct star{
    int X;
    int Y;
    };
struct star s[21];

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
			s[i].Y = s[i].Y+1;
		}
	}
}

void fill_star_to_buffer()
{
	int i, starco;
	for (i = 0; i < 20; ++i){
		consoleBuffer[s[i].X + screen_x * s[i].Y].Char.AsciiChar = '*';
		consoleBuffer[s[i].X + screen_x * s[i].Y].Attributes = 7;
	}
}


int ship_to_buffer(int x,int y)
{
    consoleBuffer[x-1 + screen_x * y].Char.AsciiChar = '<';
	consoleBuffer[x + screen_x * y].Char.AsciiChar = '>';
	consoleBuffer[x-1 + screen_x * y].Attributes = colour;
	consoleBuffer[x + screen_x * y].Attributes = colour;	
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
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

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}


int main()
{
	int life = 10;
    bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    srand(time(NULL));
    setMode();
    DWORD i;
    int posx, posy, st;
    init_star();

    while (play)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0) {
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (i = 0; i < numEventsRead; ++i) {
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true ) {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                        play = false;
                    }
                    if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 99) {
                        colour = (rand() % 10) + 1;
                    }
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT) {
                    posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                }
            }
        }
        
        for (st = 0; st < 20; st++){
			if (posx == s[st].X && posy == s[st].Y || posx == (s[st].X) + 1 && posy == (s[st].Y) + 1){
				s[st].X = (rand() % screen_x);
				s[st].Y = 1;
				life--;
				if (life <= 1){
					play = false;
				}
			}
		}
		
        star_fall();
        clear_buffer();
        fill_star_to_buffer();
        ship_to_buffer(posx,posy);
		fill_buffer_to_console();
        Sleep(100);
    }
    return 0;
}
