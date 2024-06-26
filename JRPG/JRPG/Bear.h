#pragma once
class Bear : public Enemy
{
public:
	Bear(Stat bearStat);
	wstring visual[7] =
	{
		 L"__         __",
		 L" / \\. - \"\"\"-./  \"",
		 L"\\    -    -    /",
		 L" |   o   o     | ",
		 L" \\  . - '''-. /"
		 L"  '-\\__Y__/-'",
		 L"     `---`"
	};
};

