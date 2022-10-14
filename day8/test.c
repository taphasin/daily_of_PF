#include <stdio.h>
#include <windows.h>
#include <time.h>
#define scount 80
#define screen_x 80
#define screen_y 25
int color=7;
bool play=true;
int shipx;
int shipy;
int count=0;
int posx;
int posy;

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
DWORD numEvents = 0;
DWORD numEventsRead = 0;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
COORD star[scount];

	struct star{
		int starx;
		int stary;
	} st[80];
	
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}	

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) 
	{
		for (int x = 0; x < screen_x; ++x) 
		{
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
	for(int i=0;i<scount;i++)
	{
		st[i].starx = rand()%screen_x;
		st[i].stary = rand()%screen_y;
	}
	
}

void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) 
	{
		if (st[i].stary >= screen_y-1) 
		{
			st[i].starx=rand()%screen_x;
			st[i].stary=1;
		}
		else 
		{
			st[i].stary += 1;
		}
	}
}

void fill_star_to_buffer()
{
	for (int i=0;i<scount;i++) 
	{
		consoleBuffer[st[i].starx + screen_x * st[i].stary].Char.AsciiChar = '*';
		consoleBuffer[st[i].starx + screen_x * st[i].stary].Attributes = 7;
	
	}
}

void fill_ship_to_buffer(int x,int y,int color)
{
	consoleBuffer[x + screen_x * y].Char.AsciiChar = '<';
	consoleBuffer[x+1 + screen_x * y].Char.AsciiChar = '-';
	consoleBuffer[x+2 + screen_x * y].Char.AsciiChar = 'O';
	consoleBuffer[x+3 + screen_x * y].Char.AsciiChar = '-';
	consoleBuffer[x+4 + screen_x * y].Char.AsciiChar = '>';
	consoleBuffer[x + screen_x * y].Attributes = color;
	consoleBuffer[x+1 + screen_x * y].Attributes = color;	
	consoleBuffer[x+2 + screen_x * y].Attributes = color;	
	consoleBuffer[x+3 + screen_x * y].Attributes = color;	
	consoleBuffer[x+4 + screen_x * y].Attributes = color;	

}


int main()
{
	int i;
	srand(time(NULL));
	setcursor(0);
	setConsole(screen_x, screen_y);
	init_star();
	setMode();
	while (play)
	{
		star_fall();
		clear_buffer();
		fill_star_to_buffer();
		fill_ship_to_buffer(shipx,shipy,color);
		fill_buffer_to_console();	
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) 
		{
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) 
			{
				if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true ) 
				{
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) //ESC
					{
						play = false;
					}
					else if(eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
					{
						color=rand()%14+1;
						
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) 
				{
					posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) 
					{
						color=rand()%14+1;
					}
					
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags &MOUSE_MOVED) 
					{
						shipx=posx;
						shipy=posy;
					}
				}
			}
			delete[] eventBuffer;
		}
		
		for(int i=0;i<scount;i++)
		{
			if((shipx==st[i].starx || shipx+1==st[i].starx || shipx+2==st[i].starx || shipx+3==st[i].starx || shipx+4==st[i].starx)&&shipy==st[i].stary) 
			{
				count++;
				st[i].starx=rand()%screen_x;
				st[i].stary=1;
			}
			
			if(count == 10) 
			{
				play=false;
			}
		}
		Sleep(100);
	}
return 0;
}