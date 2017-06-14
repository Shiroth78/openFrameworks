#pragma once

#include "ofxBox2d.h"

class CustomRect :public ofxBox2dRect {
public:
	CustomRect(int _num); //コンストラクタ
	void update();

	int num; //パーティクル番号
	ofSoundPlayer mySound; 
	float soundSpeed; //再生速度
	float amp; //音量
	float lfo; //パーティクル伸縮速度
	float radius;
};