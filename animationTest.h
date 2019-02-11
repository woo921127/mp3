#pragma once
#include "gameNode.h"
#include "effect.h"

class animationTest : public gameNode
{
private:
	image* _camel;
	animation* _ani1;	//디폴트 애니메이션
	animation* _ani2;	//배열 애니메이션
	animation* _ani3;	//구간 애니메이션

	effect* _effect;

public:
	animationTest();
	~animationTest();

	HRESULT init();
	void release();
	void update();
	void render();
};

