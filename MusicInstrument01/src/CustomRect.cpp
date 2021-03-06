#include "CustomRect.h"

CustomRect::CustomRect(int _num) {
	num = _num;
	//音程配列生成
	float notes[] = { 1.0, 5.0 / 4.0, 4.0 / 3.0, 3.0 / 2.0 };
	float base[] = { 8.0, 4.0, 2.0, 1.0, 0.5 };
	mySound.loadSound("se01.wav");
	soundSpeed = notes[num % 4] / base[num % 5]; //音程決定
	mySound.setSpeed(soundSpeed); //設定した速度で再生
	mySound.setLoop(true);
	amp = 0; //音量０
	mySound.play();
	lfo = ofRandom(0.5, 2.0); //円の伸縮速度設定
}

void CustomRect::update() {
	radius = sin(ofGetElapsedTimef()*10.0*lfo) * 20 + 40;
	//中心からの距離計算
	ofVec2f pos = getPosition();
	float dist = pos.distance(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2));
	//距離によって音量計算
	amp = (1.0 - dist / 400.0)*0.2;
	if (amp < 0) {
		amp = 0;
	}
	mySound.setVolume(amp); //音量設定
}