#include "Information.h"

void RenderInformation()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 4.3;
	int y = Resolution.Y / 3;
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);


	Gotoxy(x, y - 6);
	wcout << L"████████████████████████████████████████████████████████████" << '\n';
	Gotoxy(x, y - 5);
	wcout << L"██                                                        ██" << '\n';
	Gotoxy(x, y - 4);
	wcout << L"██                                                        ██" << '\n';
	Gotoxy(x, y - 3);
	wcout << L"██                                                        ██" << '\n';
	Gotoxy(x, y - 2);
	wcout << L"████████████████████████████████████████████████████████████" << '\n';
}