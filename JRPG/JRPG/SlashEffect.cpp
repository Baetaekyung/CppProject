#include "SlashEffect.h"

void SlashEffect::PlayAnimation()
{
	for (int i = 0; i < visual->length(); i++)
	{
		wcout << visual[i] << '\n';
		Sleep(100);
	}
}
