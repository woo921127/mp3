#pragma once
#include "gameNode.h"
#include "pixelCollision.h"
#include "animationTest.h"
#include "soundManager.h"
#include <commdlg.h>


enum {
	PLAYONE = 1,
	PLAYTWO,
	PLAYTHREE,
	PLAYFORE,
	PLAYFIVE,
	PLAYSIX
};

class playGround : public gameNode
{
private:
	pixelCollision* _pixel;
	animationTest* _at;
	soundManager* _sound;
	
	char _str[128];

	RECT _listrc;
	RECT _startrc;
	RECT _stoprc;
	RECT _pauserc;
	RECT _remuterc;
	RECT _muterc;
	RECT _pushrc;
	RECT _backrc;
	RECT _playingbar;
	RECT _plbar;

	image* singus;

	int check;

	RECT _volumerc;
	RECT _voltrc;
	int playNum;
	float volumeMax;
	string num1;
	float _mx, _my;

	RECT _openbar;
	bool _drag;

	RECT _rc[10];

	int music;

	int numcount;

	int playtime;
	int playtime2;
	float _ms;
	float _length;
	float _MSlength;

	int _index;
	int _move;
	int choiceNum;
	POINT bar;

	float x, y;
	bool change;
	bool imgcheck;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	
	void volumesetting();
	void play();
	void boxchoice();

	playGround();
	~playGround();



};

