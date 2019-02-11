#include "stdafx.h"
#include "animationTest.h"


animationTest::animationTest()
{
}


animationTest::~animationTest()
{
}

HRESULT animationTest::init()
{
	_camel = IMAGEMANAGER->addFrameImage("낙타", "camel.bmp", 300, 267, 4, 3, true, RGB(255, 0, 255));

	//디폴트
	_ani1 = new animation;
	_ani1->init(_camel->GetWidth(), _camel->GetHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani1->setDefPlayFrame(true, true);
	_ani1->setFPS(1);

	//배열 재생
	int arrAni[] = { 11, 1, 5, 7, 2, 6, 4, 8 };
	_ani2 = new animation;
	_ani2->init(_camel->GetWidth(), _camel->GetHeight(),
		_camel->getFrameWidth(), _camel->getFrameHeight());
	_ani2->setPlayFrame(arrAni, 8, true);
	_ani2->setFPS(1);

	_ani3 = new animation;
	_ani3->init(_camel->GetWidth(), _camel->GetHeight(),
		_camel->getFrameWidth(), _camel->getFrameHeight());
	_ani3->setPlayFrame(2, 8, false, true);
	_ani3->setFPS(1);

	IMAGEMANAGER->addImage("마이클베이형", "explosion.bmp", 832, 62, true, RGB(255, 0, 255));

	_effect = new effect;
	_effect->init(IMAGEMANAGER->findImage("마이클베이형"), 32, 62, 1.0f, 1.0f);

	EFFECTMANAGER->addEffect("explosion", "explosion.bmp", 832, 62, 32, 62, 1.0f, 0.1f, 1000);

	return S_OK;
}

void animationTest::release()
{
}

void animationTest::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q')) _ani1->start();
	if (KEYMANAGER->isOnceKeyDown('W')) _ani2->start();
	if (KEYMANAGER->isOnceKeyDown('E')) _ani3->start();

	_ani1->frameUpdate(TIMEMANAGER->getElpasedTime() * 10);
	_ani2->frameUpdate(TIMEMANAGER->getElpasedTime() * 20);
	_ani3->frameUpdate(TIMEMANAGER->getElpasedTime() * 30);

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		_effect->startEffect(_ptMouse.x, _ptMouse.y);
	}
	_effect->update();

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		EFFECTMANAGER->play("explosion", _ptMouse.x, _ptMouse.y);
	}

	EFFECTMANAGER->update();
}

void animationTest::render()
{
	_camel->aniRender(getMemDC(), 100, 100, _ani1);
	_camel->aniRender(getMemDC(), 300, 100, _ani2);
	_camel->aniRender(getMemDC(), 500, 100, _ani3);

	_effect->render();

	EFFECTMANAGER->render();
}
