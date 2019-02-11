#pragma once
#include "gameNode.h"
#include <vector>


class Bullet : public gameNode
{
private:
	image* _bulletImage;		//�Ѿ��̹���
	RECT _rc;					//�Ѿ˷�Ʈ
	float _x, _y;				//�Ѿ� ��ǥ
	float _fireX, _fireY;		//�Ѿ� �߻���ġ(X,Y)
	float _angle;				//�Ѿ� ����
	float _radius;				//�Ѿ� ������
	float _speed;				//�Ѿ� ���ǵ�
	float _range;				//�Ѿ� �ִ� ��Ÿ�
	
	bool _isActive;
public:
	Bullet();
	~Bullet();

	void init(image* image, float radius, float range);
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float angle, float speed);

	void bulletMove();

public:

	//Ȱ������ �Ѿ� ����
	void setActive(bool isActive)	{ _isActive = isActive; }
	bool getActive() const			{ return _isActive; }

	RECT getRC() const				{ return _rc; }
};

//�淿 Ǯ~
class BulletPool
{
private:
	float _defaultRange;
	float _defaultRadius;
	const char* _imageName;

	vector<Bullet*> _disableBullets;//�Ⱦ��°�
	vector<Bullet*> _enableBullets;//���°�
public:
	BulletPool();
	~BulletPool();

	void init(const char* imageName, int createBullet = 16000, float range = 1200.0f, float radius = 10.0f);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);


public:
	//�߻�� �Ѿ� ����
	vector<Bullet*> getActiveBullets()const { return _enableBullets; }
};
