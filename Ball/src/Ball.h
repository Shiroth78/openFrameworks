#pragma once
#include "ofMain.h"

class Ball
{
private:
	ofPoint pos; //�~�̈ʒu
	float radius; //�~�̔��a
	ofPoint speed; //�~�̑��x
	float phase; //�~�̐L�k�ʑ�
	float phaseSpeed; //�~�̐L�k���x
	float strechedRadius; //�L�k�㔼�a

public:
	Ball(); // �R���X�g���N�^
	void draw();
	void update();
	void setRadius(float radius); //radius�Z�b�^�[
	float getRadius(); //radius�Q�b�^�[
	void setPos(ofPoint pos); //pos�Z�b�^�[
	ofPoint getPos(); //pos�Q�b�^�[
	void setSpeed(ofPoint speed); //speed setter
	ofPoint getSpeed(); // speed getter
};

