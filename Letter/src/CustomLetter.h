#pragma once

#include "ofxBox2d.h"

class CustomLetter :public ofxBox2dRect {
public:
	CustomLetter();
	void update();
	void draw();

	//int num; //�p�[�e�B�N���ԍ�
	//ofSoundPlayer mySound;
	ofTrueTypeFont font; //�t�H���g
	char letter; //����
	float scale; //�X�P�[��
	int r, g, b; //�F
	float w, h; //bounding box
};
	