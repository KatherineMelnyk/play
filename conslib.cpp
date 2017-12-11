#ifdef _WIN32

#include <windows.h>

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void setCursorVisibility(bool isVisible)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = isVisible;
	SetConsoleCursorInfo(out, &cursorInfo);
}


void pause(int ms)
{
	Sleep(ms);
}

#else

#include <unistd.h>
#include <term.h>

void gotoxy(int x, int y)
{
	int err;
	if (!cur_term)
		if (setupterm(NULL, STDOUT_FILENO, &err) == ERR)
			return;
	putp(tparm(tigetstr("cup"), y, x, 0, 0, 0, 0, 0, 0, 0));
}

void pause(int ms)
{

}

void setCursorVisibility(bool isVisible) {

}

#endif 

#include <stdio.h>
#include <conio.h>

void printat(int x, int y, char *s)
{
	gotoxy(x, y);
	printf(s);
}

char waitAnyKey()
{
	return _getch();
}

void(*frameFunc)() = nullptr;
bool(*idleFunc)() = nullptr;

void startAnimation()
{
	bool needStop = false;
	while (!needStop)
	{
		if (frameFunc != nullptr) frameFunc();
		if (idleFunc != nullptr) needStop = idleFunc();
	}
}

void setOnFrame(void(*frameFunc)())
{
	::frameFunc = frameFunc;
}
void setOnIdle(bool(*idleFunc)())
{
	::frameFunc = frameFunc;
}