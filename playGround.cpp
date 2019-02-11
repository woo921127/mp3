#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);

	//IMAGEMANAGER->addImage("��׶���", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_sound = new soundManager;
	_sound->init();
		
	IMAGEMANAGER->addImage("��ŸƮ", "startButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ž", "stopButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ͻ�����", "pauseButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ŀ", "remuteButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ұ�", "muteButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ڷ�", "backButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "pushButten.bmp", 52, 52, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "�������.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ȹٴ�", "�����ȹٴ�.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ſ���", "�ſ���.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ǻ���", "���ǻ���.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�μ����ð�", "�μ����ð�.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "��������.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ȯ������", "ȯ������.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ǵ�", "����Ǵ�.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("1", "num1.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("2", "num2.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3", "num3.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("4", "num4.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("5", "num5.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("6", "num6.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("7", "num7.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("8", "num8.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("9", "num9.bmp", 100, 50, true, RGB(255, 0, 255));

	singus = IMAGEMANAGER->addFrameImage("�ñ׳ʽ�����", "�ñ׳ʽ�����.bmp", 8400, 300, 28, 1, true, (RGB(255, 0, 255)));

	volumeMax = 1.f;

	_listrc = RectMakeCenter(210, WINSIZEY / 2, 300, 300);
	_startrc = RectMakeCenter(100, WINSIZEY - 100, 52, 52);
	_stoprc = RectMakeCenter(170, WINSIZEY - 100, 52, 52);
	_remuterc = RectMakeCenter(240, WINSIZEY - 100, 52, 52);
	_muterc = RectMakeCenter(310, WINSIZEY - 100, 52, 52);
	_backrc = RectMakeCenter(135, WINSIZEY - 40, 52, 52);
	_pushrc = RectMakeCenter(275, WINSIZEY - 40, 52, 52);
	_playingbar = RectMake(470, WINSIZEY - 50, 300, 30);
	

	 SOUNDMANAGER->addSound("maple1", "Esfera_A Place Where Life Begins.mp3",true,false); // ������ ���۵Ǵ°�
	 SOUNDMANAGER->addSound("maple2", "Esfera_ Contaminated Sea.mp3", true, false); // ������ �ٴ�
	 SOUNDMANAGER->addSound("maple3", "Esfera_ Le Temple du Miroir.mp3", true, false); // �ſ���
	 SOUNDMANAGER->addSound("maple4", "Esfera_ The Bloody Cage.mp3", true, false); // ���� ����
	 SOUNDMANAGER->addSound("maple5", "Shattered Time.mp3", true, false); // �μ��� �ð�
	 SOUNDMANAGER->addSound("maple6", "Dream Fragments.mp3", true, false); // ���� ����
	 SOUNDMANAGER->addSound("maple7", "Phantasmal Woods.mp3", true, false); // ȯ�� ����
	 SOUNDMANAGER->addSound("maple8", "Swamp of Memory.mp3", true, false); // ����� ��
	 SOUNDMANAGER->addSound("maple9", "Cygnus garden.mp3", true, false); // �ñ׳ʽ��� ����

	 _volumerc = RectMakeCenter(630, 500, 110, 10);
	 _voltrc = RectMakeCenter(680, 500, 10, 30);


	// playNum = 1;
	// music = 1;
	// sprintf_s(_str, "maple1", music);
	// SOUNDMANAGER->play(_str, volumeMax);

	 for (int i = 0; i < 9; ++i)
	 {
		 if (i < 3)
		 {
			 _rc[i] = RectMake(440 + (i * 110), 150, 100, 50);
		 }
		 if (i >= 3 && i < 6)
		 {
			 _rc[i] = RectMake(440 + ((i-3) * 110), 250, 100, 50);
		 }
		 if (i >= 6 && i < 9)
		 {
			 _rc[i] = RectMake(440 + ((i - 6) * 110), 350, 100, 50);
		 }
	 }
	 

	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();

	volumesetting();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_backrc, _ptMouse))
		{
			if (music > 1)
			{
				music -= 1;
			}
			if (KEYMANAGER->isToggleKey('Q'))
			{
				music = RND->getFromIntTo(1, 9);
			}
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_pushrc, _ptMouse))
		{
			if (music < 9)
			{
				music += 1;
			}
			if (KEYMANAGER->isToggleKey('Q'))
			{
				music = RND->getFromIntTo(1, 9);
			}
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}


		play();
		boxchoice();
	}
	if (KEYMANAGER->isToggleKey('Q'))
	{
		numcount = 1;
		if (SOUNDMANAGER->getLength(_str) - 100 <= SOUNDMANAGER->getMs(_str))
		{
			music = RND->getFromIntTo(1, 9);
		}
	}


	_ms = SOUNDMANAGER->getMs(_str);
	_length = SOUNDMANAGER->getLength(_str);
	_MSlength = (_ms/ _length)*300;
	_plbar = RectMake(470, WINSIZEY - 50, _MSlength, 30);

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_playingbar, _ptMouse))
		{
			for (int i = 470; i < 770 ; ++i)
			{
				if (_ptMouse.x == i)
				{
					SOUNDMANAGER->setMs(_str, (_length / 300) * (i-470));
				}
			}
		}
	}


	if (SOUNDMANAGER->getLength(_str) - 100 <= SOUNDMANAGER->getMs(_str))
	{
		if (music == 9)
		{
			music = 1;
		}
	
		else
		{
			music += 1;
		}
		SOUNDMANAGER->stop(_str);
		sprintf_s(_str, "maple%d", music);
		SOUNDMANAGER->play(_str, volumeMax);
	}

	if (music == 9)
	{
		_move++;

		if (_move % 2 == 0)
		{
			_index++;
			singus->SetFrameX(_index);
			if (_index > 27) _index = 0;
		}
	}


	playtime = (SOUNDMANAGER->getLength(_str) / 1000 / 60);
	playtime2 = (SOUNDMANAGER->getMs(_str) / 1000 / 60);
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	Rectangle(getMemDC(), _listrc);
	Rectangle(getMemDC(), _volumerc);
	Rectangle(getMemDC(), _voltrc);
	Rectangle(getMemDC(), _playingbar);
	
	for (int i = 0; i < 9; ++i)
	{
		Rectangle(getMemDC(), _rc[i]);

	}

	IMAGEMANAGER->findImage("1")->render(getMemDC(), _rc[0].left, _rc[0].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("2")->render(getMemDC(), _rc[1].left, _rc[1].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("3")->render(getMemDC(), _rc[2].left, _rc[2].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("4")->render(getMemDC(), _rc[3].left, _rc[3].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("5")->render(getMemDC(), _rc[4].left, _rc[4].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("6")->render(getMemDC(), _rc[5].left, _rc[5].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("7")->render(getMemDC(), _rc[6].left, _rc[6].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("8")->render(getMemDC(), _rc[7].left, _rc[7].top, 0, 0, 100, 50);
	IMAGEMANAGER->findImage("9")->render(getMemDC(), _rc[8].left, _rc[8].top, 0, 0, 100, 50);
	if (change == false)
	{
		IMAGEMANAGER->findImage("�Ͻ�����")->render(getMemDC(), _startrc.left, _startrc.top, 0, 0, 52, 52);
	}
	if (change == true)
	{
		IMAGEMANAGER->findImage("��ŸƮ")->render(getMemDC(), _startrc.left, _startrc.top, 0, 0, 52, 52);

	}
	IMAGEMANAGER->findImage("��ž")->render(getMemDC(), _stoprc.left, _startrc.top, 0, 0, 52, 52);
	IMAGEMANAGER->findImage("����Ŀ")->render(getMemDC(), _remuterc.left, _remuterc.top, 0, 0, 52, 52);
	IMAGEMANAGER->findImage("���Ұ�")->render(getMemDC(), _muterc.left, _muterc.top, 0, 0, 52, 52);
	IMAGEMANAGER->findImage("�ڷ�")->render(getMemDC(), _backrc.left, _backrc.top, 0, 0, 52, 52);
	IMAGEMANAGER->findImage("������")->render(getMemDC(), _pushrc.left, _pushrc.top, 0, 0, 52, 52);
	char str[128];
	if (imgcheck == false)
	{
		if (music == 1)
		{
			IMAGEMANAGER->findImage("�������")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : A Place Where Life Begins");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 2)
		{
			IMAGEMANAGER->findImage("�����ȹٴ�")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : Contaminated Sea");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 3)
		{
			IMAGEMANAGER->findImage("�ſ���")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : Le Temple du Miroir");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 4)
		{
			IMAGEMANAGER->findImage("���ǻ���")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : The Bloody Cage");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 5)
		{
			IMAGEMANAGER->findImage("�μ����ð�")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : Shattered Time");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 6)
		{
			IMAGEMANAGER->findImage("��������")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : Dream Fragments");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 7)
		{
			IMAGEMANAGER->findImage("ȯ������")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : Phantasmal Woods");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 8)
		{
			IMAGEMANAGER->findImage("����Ǵ�")->render(getMemDC(), _listrc.left, _listrc.top, 0, 0, 300, 300);
			sprintf_s(str, "������� �뷡 : Swamp of Memory");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		}
		if (music == 9)
		{

			IMAGEMANAGER->findImage("�ñ׳ʽ�����")->frameRender(getMemDC(), _listrc.left, _listrc.top, singus->getFrameX(), 0);
			sprintf_s(str, "������� �뷡 : Cygnus garden");
			TextOut(getMemDC(), WINSIZEX / 2 - 150, 100, str, strlen(str));
		
		}

	}
	


	if (KEYMANAGER->isToggleKey('Q'))
	{
		sprintf_s(str, "������", music, volumeMax, numcount);
		TextOut(getMemDC(), WINSIZEX / 2 + 100, 50, str, strlen(str));
	}
	sprintf_s(str, "�÷��̳ѹ� : %d  ���� : %f ", music, volumeMax );
	TextOut(getMemDC(), WINSIZEX / 2 - 150, 50, str, strlen(str));
	sprintf_s(str, "%0.2d:%0.2d", playtime2, (SOUNDMANAGER->getMs(_str) / 1000) % 60);
	TextOut(getMemDC(), WINSIZEX / 2 + 60, WINSIZEY - 70, str, strlen(str));

	sprintf_s(str, "%d:%d ", playtime, (SOUNDMANAGER->getLength(_str) / 1000) % 60);
	TextOut(getMemDC(), WINSIZEX - 50, WINSIZEY - 70, str, strlen(str));

	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(getMemDC(), brush);
	Rectangle(getMemDC(), _plbar);
	SelectObject(getMemDC(), oldbrush);
	DeleteObject(brush);
	DeleteObject(oldbrush);

	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
void playGround::volumesetting()
{
	if (KEYMANAGER->isStayKeyDown('1'))
	{
		if (_voltrc.left >= _volumerc.left)
		{
			_voltrc.left -= 1;
			_voltrc.right -= 1;
			if (volumeMax > 0)
			{
				volumeMax -= 0.01f;
			}
			SOUNDMANAGER->volume(_str,volumeMax);

			if (volumeMax <= 0)
			{
				volumeMax = 0.0f;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown('2'))
	{
		if (_voltrc.right <= _volumerc.right)
		{
			_voltrc.right += 1;
			_voltrc.left += 1;
			if (volumeMax < 1.0f)
			{
				volumeMax += 0.01f;
			}
			SOUNDMANAGER->volume(_str,volumeMax);

			if (volumeMax >= 1.0f)
			{
				volumeMax = 1.0f;
			}
		}
	}
}

void playGround::play()
{
		if (PtInRect(&_stoprc, _ptMouse))
		{
			SOUNDMANAGER->stop(_str);
		}
		if (PtInRect(&_muterc, _ptMouse))
		{
			SOUNDMANAGER->mute(_str);
			volumeMax = 0;
			if (_voltrc.left >= _volumerc.left)
			{
				_voltrc.left = _volumerc.left - 0.1f;
				_voltrc.right = _voltrc.left + 10;
			}
		}
		if (PtInRect(&_remuterc, _ptMouse))
		{
			SOUNDMANAGER->remute(_str);
			volumeMax = 1.0f;
			if (_voltrc.right <= _volumerc.right)
			{
				_voltrc.left = _volumerc.left + 100;
				_voltrc.right = _volumerc.right + 1.0f;
			}
		}
		if (PtInRect(&_startrc, _ptMouse))
		{
			if (change == false)
			{
				SOUNDMANAGER->pause(_str);
				change = true;
			}
			else if (change == true)
			{
				SOUNDMANAGER->resume(_str);
				change = false;
			}
		}
	
}

void playGround::boxchoice()
{
		if (PtInRect(&_rc[0], _ptMouse))
		{
			choiceNum = 1;
			music = 1;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[1], _ptMouse))
		{
			choiceNum = 2;
			music = 2;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[2], _ptMouse))
		{
			choiceNum = 3;
			music = 3;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);

		}
		if (PtInRect(&_rc[3], _ptMouse))
		{
			choiceNum = 4;
			music = 4;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[4], _ptMouse))
		{
			choiceNum = 5;
			music = 5;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[5], _ptMouse))
		{
			choiceNum = 6;
			music = 6;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[6], _ptMouse))
		{
			choiceNum = 7;
			music = 7;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[7], _ptMouse))
		{
			choiceNum = 8;
			music = 8;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}
		if (PtInRect(&_rc[8], _ptMouse))
		{
			choiceNum = 9;
			music = 9;
			SOUNDMANAGER->stop(_str);
			sprintf_s(_str, "maple%d", music);
			SOUNDMANAGER->play(_str, volumeMax);
		}	
}

