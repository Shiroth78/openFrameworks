#include "CustomRect.h"

CustomRect::CustomRect(int _num) {
	num = _num;
	//�����z�񐶐�
	float notes[] = { 1.0, 5.0 / 4.0, 4.0 / 3.0, 3.0 / 2.0 };
	float base[] = { 8.0, 4.0, 2.0, 1.0, 0.5 };
	mySound.loadSound("se01.wav");
	soundSpeed = notes[num % 4] / base[num % 5]; //��������
	mySound.setSpeed(soundSpeed); //�ݒ肵�����x�ōĐ�
	mySound.setLoop(true);
	amp = 0; //���ʂO
	mySound.play();
	lfo = ofRandom(0.5, 2.0); //�~�̐L�k���x�ݒ�
}

void CustomRect::update() {
	radius = sin(ofGetElapsedTimef()*10.0*lfo) * 20 + 40;
	//���S����̋����v�Z
	ofVec2f pos = getPosition();
	float dist = pos.distance(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2));
	//�����ɂ���ĉ��ʌv�Z
	amp = (1.0 - dist / 400.0)*0.2;
	if (amp < 0) {
		amp = 0;
	}
	mySound.setVolume(amp); //���ʐݒ�
}