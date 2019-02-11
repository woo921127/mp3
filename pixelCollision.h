#pragma once
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _hill;
	image* _ball;


	RECT _rc;		//공의 렉트
	float _x, _y;	//공의 중점좌표

	int _probeY;	//Y축 탐사용 변수

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release();
	void update();
	void render();
};

