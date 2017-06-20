#pragma once

#include "ofxBox2d.h"

class CustomLetter :public ofxBox2dRect {
public:
	CustomLetter();
	void update();
	void draw();

	//int num; //パーティクル番号
	//ofSoundPlayer mySound;
	ofTrueTypeFont font; //フォント
	char letter; //文字
	float scale; //スケール
	int r, g, b; //色
	float w, h; //bounding box
};
	