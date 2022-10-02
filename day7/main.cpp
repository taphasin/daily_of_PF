#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

int st = 0;

void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}

void draw_star(int x, int y)
{
 COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    setcolor(7,0);
    printf("*");
    st++;
}

void draw_score(int z){
	COORD c = { 90 , 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    printf("score : %d", z);
}

void setcursor(bool visible)
{
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_CURSOR_INFO lpCursor;
 lpCursor.bVisible = visible;
 lpCursor.dwSize = 20;
 SetConsoleCursorInfo(console,&lpCursor);
}
void erase_ship(int x,int y)
{
 COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    setcolor(4,0);
    printf("        ");
}
void draw_ship(int x, int y)
{
 COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    setcolor(4,2);
    printf(" <-0->");
}

void draw_bull(int x, int y)
{
 COORD c = { x, y - 2};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    setcolor(7,0);
    printf("o");
}

void erase_bull(int x,int y)
{
 COORD c = { x, y - 2};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    setcolor(7,0);
    printf(" ");
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
	int bull = 0;
	int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0;
	char sta, sb;
	int sy, sx;
    char ch=' ';
    int x=0,y=20;
    int x1 = x,x2 = x,x3 = x,x4 = x,x5 = x;
    int y1 = y,y2 = y,y3 = y,y4 = y,y5 = y;
    int numbull = 0;
    char sb1, sb2, sb3, sb4, sb5, z;
    srand(time(NULL));
    setcursor(0);
 	draw_score(0);
 	
    draw_ship(x,y);
    do {
    if (_kbhit())
    {
        ch = _getch();
        if(ch=='a' && x >= 1) {erase_ship(x,y);draw_ship(--x,y);sta = 'a';}
    	if(ch=='d' && x <= 80) {erase_ship(x,y);draw_ship(++x,y);sta = 'd';}
    	if(ch=='s' && y <= 27) {draw_ship(x,y);sta = 's';}
    	if(ch==' ' && bull < 5) {
    		Beep(1000,200);
			sb = 'f';
			numbull += 1;
			if (numbull > 5) {numbull = 1;}
			if (numbull == 1) {x1 = x, y1 = y;b1 = 1;}
			if (numbull == 2) {x2 = x, y2 = y;b2 = 1;}
			if (numbull == 3) {x3 = x, y3 = y;b3 = 1;}
			if (numbull == 4) {x4 = x, y4 = y;b4 = 1;}
			if (numbull == 5) {x5 = x, y5 = y;b5 = 1;}
		} 
    	fflush(stdin);
	}
	
	
	bull = 0;
	if(sta =='a' && x >= 1) {erase_ship(x,y);draw_ship(--x,y);}	
	if(sta =='d' && x <= 80) {erase_ship(x,y);draw_ship(++x,y);}
    if(sta =='s' && y <= 27) {draw_ship(x,y);}
    
    sb1 = cursor(x1,y1 - 4);
    sb2 = cursor(x2,y2 - 4);
    sb3 = cursor(x3,y3 - 4);
    sb4 = cursor(x4,y4 - 4);
    sb5 = cursor(x5,y5 - 4);
    printf("%c", sb1);
	if (sb1 == '*'){b1 = 0; st--; erase_bull(x1,y1 - 2);z++;draw_score(z);Beep(1000,200);}
	if (sb2 == '*'){b2 = 0; st--; erase_bull(x2,y2 - 2);z++;draw_score(z);Beep(1000,200);}
	if (sb3 == '*'){b3 = 0; st--; erase_bull(x3,y3 - 2);z++;draw_score(z);Beep(1000,200);}
	if (sb4 == '*'){b4 = 0; st--; erase_bull(x4,y4 - 2);z++;draw_score(z);Beep(1000,200);}
	if (sb5 == '*'){b5 = 0; st--; erase_bull(x5,y5 - 2);z++;draw_score(z);Beep(1000,200);}
    
    if (sb == 'f') {
    	if(b1 == 1 && y1 >= 3) {
			draw_bull(x1,--y1);
			bull += 1;
		}
		else if ( y1 < 3){b1 = 0;}
		
		if(b2 == 1 && y2 >= 3) {
			draw_bull(x2,--y2);
			bull += 1;
		}
		else if( y2 < 3 ){b2 = 0;}
		
		if(b3 == 1 && y3 >= 3) {
			draw_bull(x3,--y3);
			bull += 1;
		}
		else if( y3 < 3 ){b3 = 0;}
		
		if(b4 == 1 && y4 >= 3) {
			draw_bull(x4,--y4);
			bull += 1;
		}
		else if( y4 < 3 ){b4 = 0;}
		
		if(b5 == 1 && y5 >= 3) {
			draw_bull(x5,--y5);
			bull += 1;
		}
		else if( y5 < 3 ){b5 = 0;}
	}
	
	
	if (st < 40){
		sy = (rand() % 4) + 2;
		sx = (rand() % 61) + 10;
		draw_star(sx,sy);
	}
	
    Sleep(100);
    erase_bull(x1,y1);
    erase_bull(x2,y2);
    erase_bull(x3,y3);
    erase_bull(x4,y4);
    erase_bull(x5,y5);
    } while (ch!='x');
    return 0;
}
