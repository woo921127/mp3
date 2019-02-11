#pragma once
#include "gameNode.h"
#include <vector>

//�Ѿ� ����ü
struct tagBullet
{
	image* bulletImage;		//�Ѿ��̹���
	RECT rc;				//�Ѿ˷�Ʈ
	float x, y;				//�Ѿ� ��ǥ
	float angle;			//�Ѿ� ����
	float radius;			//�Ѿ� ������
	float speed;			//�Ѿ� ���ǵ�
	float fireX, fireY;		//�Ѿ� �߻���ġ(X,Y)
	bool isFire;
	int count;
};

//������ ��밡���� �Ѿ�
class bullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char*					_imageName;
	float						_range;
	int							_bulletMax;
public:
	bullet();
	~bullet();

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float angle, float speed);

	void bulletMove();

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


//�����س��� �߻��ϴ� �̜X~
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
public:
	missile();
	~missile();

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	//�Ѿ� �߻��Լ�(������ǥX, Y)
	void fire(float x, float y);

	void move();
};
//�� �����ؼ� �߻��ϴ� �̜X~
class spear : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _missileMax;

public:
	spear();
	~spear();

	virtual HRESULT init(int missileMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	void fire(float x, float y);

	void move();

	void removeSpear(int arrNum);

	vector<tagBullet> getVSpear()			{ return _vBullet; }
	vector<tagBullet>::iterator getVISpear() { return _viBullet; }
};