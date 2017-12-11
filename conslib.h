#pragma once
#ifndef __conslib_included_
#define __conslib_included_

void gotoxy(int x, int y);
void setCursorVisibility(bool isVisible);
void printat(int x, int y, char *s);
void pause(int ms);
char waitAnyKey();

void startAnimation();
void setOnFrame(void(*frameFunc)());
void setOnIdle(bool(*idleFunc)());

#endif
