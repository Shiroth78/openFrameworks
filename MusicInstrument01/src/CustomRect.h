#pragma once

#include "ofxBox2d.h"

class CustomRect :public ofxBox2dRect {
public:
	CustomRect(int _num); //�R���X�g���N�^
	void update();

	int num; //�p�[�e�B�N���ԍ�
	ofSoundPlayer mySound; 
	float soundSpeed; //�Đ����x
	float amp; //����
	float lfo; //�p�[�e�B�N���L�k���x
	float radius;
};