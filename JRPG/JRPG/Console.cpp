#include <Windows.h>
#include "Console.h"

void FullScreen()
{
	/*SetConsoleDisplayMode
		(GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE, NULL);*/
	/*ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);*/

	::SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN,
		VK_RETURN, 0x20000000);
}

void Gotoxy(int x, int y)
{
	// �ܼ�â �ڵ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ�� ���� ����ü
	COORD cursor = { x, y }; // * 2�� �ڿ������� �� �ִ�.
	// �ܼ� Ŀ���� ��ġ�� ���� �̵���Ű�� �Լ�
	SetConsoleCursorPosition(handle, cursor);
}

BOOL GotoPos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor = { x, y };
	
	return SetConsoleCursorPosition(handle, cursor);
}

COORD GetCursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(
		STD_OUTPUT_HANDLE), &buf);

	return buf.dwCursorPosition;
}

void SetCursorVisual(bool vis, DWORD size)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = vis;
	curInfo.dwSize = size;
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&curInfo);
}

void SetColor(int textColor, int bgColor)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		(bgColor << 4) | textColor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(
		STD_OUTPUT_HANDLE), &buf);
	int color = buf.wAttributes & 0xf;
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console)
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX; // & ~WS_CAPTION ���� ���ֱ�
		SetWindowLong(console, GWL_STYLE, style);
	}
}

void SetFontSize(UINT weight, UINT sizex, UINT sizey)
{
	//����, �������� ũ��� ��Ű�쳪��?
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hOut, false, &font);
	font.FontWeight = weight;
	font.dwFontSize.X = sizex;
	font.dwFontSize.Y = sizey;
	SetCurrentConsoleFontEx(hOut, false, &font);
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(
		STD_OUTPUT_HANDLE), &buf);
	short width = buf.srWindow.Right - buf.srWindow.Left + 1;
	short height = buf.srWindow.Bottom - buf.srWindow.Top + 1;
	return COORD{ width, height };
}

CONSOLE_FONT_INFOEX GetFontSize()
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hOut, false, &font);

	return font;
}
