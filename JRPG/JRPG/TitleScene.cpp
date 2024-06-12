#include<fcntl.h>
#include<io.h>
#include "Console.h"
#include "TitleScene.h"
void TitleRenderer() 
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 4.3;
	int y = Resolution.Y / 2;
	Gotoxy(x, y - 10);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetColor((int)COLOR::LIGHT_VIOLET);
	wcout << L"████████╗██╗   ██╗██████╗ ███╗   ██╗    ███████╗██╗ ██████╗ ██╗  ██╗████████╗███████╗██████╗	" << endl;
	Gotoxy(x, y - 9);
	wcout << L"╚══██╔══╝██║   ██║██╔══██╗████╗  ██║    ██╔════╝██║██╔════╝ ██║  ██║╚══██╔══╝██╔════╝██╔══██╗" << endl;
	Gotoxy(x ,y - 8);
	wcout << L"   ██║   ██║   ██║██████╔╝██╔██╗ ██║    █████╗  ██║██║  ███╗███████║   ██║   █████╗  ██████╔╝" << endl;
	Gotoxy(x, y - 7);
	wcout << L"   ██║   ██║   ██║██╔══██╗██║╚██╗██║    ██╔══╝  ██║██║   ██║██╔══██║   ██║   ██╔══╝  ██╔══██╗" << endl;
	Gotoxy(x, y - 6);
	wcout << L"   ██║   ╚██████╔╝██║  ██║██║ ╚████║    ██║     ██║╚██████╔╝██║  ██║   ██║   ███████╗██║  ██║" << endl;
	Gotoxy(x, y - 5);
	wcout << L"   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝" << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
	SetColor((int)COLOR::WHITE);
}

bool TitleScene() {
	while (true) {
		system("cls");
		TitleRenderer();
		Menu eMenu = MenuRender();
		switch (eMenu)
		{
		case Menu::Start:
			EnterAnimation();
			return true;
		case Menu::Help:
			InfoRender();
			break;
		case Menu::Exit:
			return false;
		}
	}
}

void InfoRender()
{
	system("cls");
	CONSOLE_FONT_INFOEX font;
	font = GetFontSize();

	UINT originW = font.FontWeight;
	UINT originX = font.dwFontSize.X;
	UINT originY = font.dwFontSize.Y;

	UINT weight = 25;
	UINT sizeX = 25;
	UINT sizeY = 25;

	COORD Resolution = GetConsoleResolution();
	SetFontSize(weight, sizeX, sizeY);
	int x = Resolution.X / 4.5;
	int y = Resolution.Y / 3.5;
	Gotoxy(x, y);
	SetColor((int)COLOR::RED);
	cout << "[조작법]" << endl << "\n";
	Gotoxy(x, y + 2);
	SetColor((int)COLOR::LIGHT_YELLOW);
	cout << "방향키 Up, Down, Left, Right로 이동합니다." << "\n";
	Gotoxy(x, y + 3);
	SetColor((int)COLOR::GREEN);
	cout << "Enter로 선택합니다." << "\n";
	Gotoxy(x, y + 4);
	SetColor((int)COLOR::BLUE);
	cout << "Esc로 메인화면으로 이동합니다." << "\n";
	Sleep(100);

	while (true)
	{
		if (KeyController() == KEY::Enter) {
			SetFontSize(originW, originX, originY);
			break;
		}
	}
}

Menu MenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.25;
	int y = Resolution.Y / 2;
	int originy = y;
	Gotoxy(x, y);
	SetColor((int)COLOR::RED);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	SetColor((int)COLOR::GREEN);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	SetColor((int)COLOR::BLUE);
	cout << "게임 종료";
	SetColor((int)COLOR::WHITE);
	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (originy < y)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (originy + 2 > y)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::Enter:
		{
			if (y == originy)
				return Menu::Start;
			else if (y == originy + 1)
				return Menu::Help;
			else if (y == originy + 1)
				return Menu::Exit;
		}
		break;
		}
	}
}

KEY KeyController()
{
	// 입력처리?
	//if(getch()) // 1
	if (GetAsyncKeyState(VK_UP) & 0x8000) // 2
	{
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 2
	{
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x8000) // 2
	{
		Sleep(50);
		return KEY::Enter;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 2
	{
		return KEY::Left;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 2
	{
		return KEY::Right;
	}
	return KEY::FAIL;
}

void EnterAnimation()
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int anitime = 1;
	system("cls");

	// 크로스 되는 애니메이션을 추가
	SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
	for (int i = 0; i < width / 2; ++i)
	{
		for (int j = 0; j < height; j += 2)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < height; j += 2)
		{
			Gotoxy(width - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(anitime);
	}
	SetColor((int)COLOR::WHITE);
	system("cls");
	StageRender();
}

void StageRender()
{
	system("cls");
	int xPos = -1;

	StageRenderText(xPos);

	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::Left:
			if (xPos > -1)
			{
				xPos--;
				StageRenderText(xPos);
			}
			break;
		case KEY::Right:
			if (xPos < 1)
			{
				xPos++;
				StageRenderText(xPos);
			}
			break;
		case KEY::Enter:
		{

		}
		break;
		}
	}
}

void StageRenderText(int a)
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.9;
	int y = Resolution.Y / 2.2;

	SetColor((int)COLOR::LIGHT_GRAY);
	Gotoxy(x, y - 10);
	wcout << L"███╗ ███████╗████████╗ █████╗  ██████╗ ███████╗ ███╗" << endl;
	Gotoxy(x, y - 9);
	wcout << L"██╔╝ ██╔════╝╚══██╔══╝██╔══██╗██╔════╝ ██╔════╝ ╚██║" << endl;
	Gotoxy(x, y - 8);
	wcout << L"██║  ███████╗   ██║   ███████║██║  ███╗█████╗    ██║" << endl;
	Gotoxy(x, y - 7);
	wcout << L"██║  ╚════██║   ██║   ██╔══██║██║   ██║██╔══╝    ██║" << endl;
	Gotoxy(x, y - 6);
	wcout << L"███╗ ███████║   ██║   ██║  ██║╚██████╔╝███████╗ ███║" << endl;
	Gotoxy(x, y - 5);
	wcout << L"╚══╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚══════╝ ╚══╝" << endl;
	SetColor((int)COLOR::WHITE);

	if (a == -1) {
		SetColor((int)COLOR::RED);
	}

	Gotoxy(x, y);
	wcout << L" ██╗" << endl;
	Gotoxy(x, y + 1);
	wcout << L"███║" << endl;
	Gotoxy(x, y + 2);
	wcout << L"╚██║" << endl;
	Gotoxy(x, y + 3);
	wcout << L" ██║" << endl;
	Gotoxy(x, y + 4);
	wcout << L" ██║" << endl;
	Gotoxy(x, y + 5);
	wcout << L" ╚═╝" << endl;
	x = Resolution.X / 2.15;
	SetColor((int)COLOR::WHITE);

	if (a == 0) {
		SetColor((int)COLOR::GREEN);
	}

	Gotoxy(x, y);
	wcout << L"██████╗ " << endl;
	Gotoxy(x, y + 1);
	wcout << L"╚════██╗" << endl;
	Gotoxy(x, y + 2);
	wcout << L" █████╔╝" << endl;
	Gotoxy(x, y + 3);
	wcout << L"██╔═══╝ " << endl;
	Gotoxy(x, y + 4);
	wcout << L"███████╗" << endl;
	Gotoxy(x, y + 5);
	wcout << L"╚══════╝" << endl;
	x = Resolution.X / 1.7;
	SetColor((int)COLOR::WHITE);

	if (a == 1) {
		SetColor((int)COLOR::BLUE);
	}

	Gotoxy(x, y);
	wcout << L"██████╗ " << endl;
	Gotoxy(x, y + 1);
	wcout << L"╚════██╗" << endl;
	Gotoxy(x, y + 2);
	wcout << L" █████╔╝" << endl;
	Gotoxy(x, y + 3);
	wcout << L" ╚═══██╗" << endl;
	Gotoxy(x, y + 4);
	wcout << L"██████╔╝" << endl;
	Gotoxy(x, y + 5);
	wcout << L"╚═════╝ " << endl;
	SetColor((int)COLOR::WHITE);
	Sleep(100);
}
