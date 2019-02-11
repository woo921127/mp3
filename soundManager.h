#pragma once
#include "singletonBase.h"
#include <map>

#include "inc/fmod.hpp"	//fmod.hpp���� ��Ŭ���
#pragma comment(lib, "lib/fmodex64_vc.lib")	//���̺귯�� ���� ���

using namespace FMOD;

#define SOUNDBUFFER 10
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundsIter;
	typedef map<string, Channel**> arrChannels;
	typedef map<string, Channel**>::iterator arrChannelsIter;

private:
	System * _system;
	Sound** _sound;
	Channel** _channel;
	float _volume;
	arrSounds _mTotalSounds;

public:
	HRESULT init();
	void release();
	void update();

	void addSound(string keyName, string soundName, bool bgm, bool loop);
	void play(string keyName, float volume = 1.0f); // 0.0 ~ 1.0f -> 0 ~ 255
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);
	void mute(string keyName, float volume = 0.0f);
	void remute(string keyName, float volume = 1.0f);
	void volume(string keyName,float volume);



	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);
	int getLength(string keyName);
	int getMs(string keyName);
	int setMs(string keyName, int x);


	soundManager();
	~soundManager();
};
