#pragma once
#include <Windows.h>
#include <iostream>
using std::cout;
using std::wcout;
using std::endl;
using std::wstring;

void FullScreen();
void Gotoxy(int x, int y);
BOOL GotoPos(int x, int y);
COORD GetCursorPos();
void SetCursorVisual(bool vis, DWORD size);
void SetColor(int textColor = 15, int bgColor = 0);
int GetColor();
void LockResize();
void SetFontSize(UINT weight, UINT sizex, UINT sizey);
COORD GetConsoleResolution();
CONSOLE_FONT_INFOEX GetFontSize();
enum class COLOR
{
    BLACK, BLUE, GREEN, SKYBLUE, RED,
    VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
    LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
    LIGHT_YELLOW, WHITE, END
};