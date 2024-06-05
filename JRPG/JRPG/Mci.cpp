#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <string>
#include "Mci.h"

UINT BgmId;
UINT EffectId;

void PlayBgm(LPCWSTR soundname, int volume)
{
	// 다시 불러왔을 때 기존꺼 닫기 위함
	mciSendCommand(BgmId, MCI_CLOSE, NULL, (DWORD)NULL);
	MCI_OPEN_PARMS openBgm;
	openBgm.lpstrElementName = soundname;
	// mp3 = mpegvideo, wav = waveaudio
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	BgmId = openBgm.wDeviceID;

	// 볼륨 로직
	std::wstring msg = L"setaudio " + std::wstring(soundname) + L" volume to "
		+ std::to_wstring(volume);
	mciSendString(msg.c_str(), NULL, NULL, NULL);



	MCI_PLAY_PARMS playBgm;
	mciSendCommand(BgmId, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
}
void PlayEffect(LPCWSTR _soundname)
{
    // PLAY
    MCI_PLAY_PARMS playEffect;
    if (EffectId != 0)
    {
        mciSendCommand(EffectId, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
        mciSendCommand(EffectId, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
        EffectId = 0;
    }
    // OPEN
    MCI_OPEN_PARMS openEffect;
    // mp3: mpegvideo, wav: waveaudio, avi: avivideo
    openEffect.lpstrDeviceType = TEXT("mpegvideo");
    openEffect.lpstrElementName = _soundname;
    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
    EffectId = openEffect.wDeviceID;


    mciSendCommand(EffectId, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
    while (mciSendCommand(EffectId, MCI_STATUS, MCI_STATUS_MODE, (DWORD_PTR)&playEffect))
    {
        break;
    }
}
