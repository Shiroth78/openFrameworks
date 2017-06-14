#include "CustomRect.h"

CustomRect::CustomRect(int _num) {
	num = _num;
	//‰¹’ö”z—ñ¶¬
	float notes[] = { 1.0, 5.0 / 4.0, 4.0 / 3.0, 3.0 / 2.0 };
	float base[] = { 8.0, 4.0, 2.0, 1.0, 0.5 };
	mySound.loadSound("se01.wav");
	soundSpeed = notes[num % 4] / base[num % 5]; //‰¹’öŒˆ’è
	mySound.setSpeed(soundSpeed); //İ’è‚µ‚½‘¬“x‚ÅÄ¶
	mySound.setLoop(true);
	amp = 0; //‰¹—Ê‚O
	mySound.play();
	lfo = ofRandom(0.5, 2.0); //‰~‚ÌLk‘¬“xİ’è
}

void CustomRect::update() {
	radius = sin(ofGetElapsedTimef()*10.0*lfo) * 20 + 40;
	//’†S‚©‚ç‚Ì‹——£ŒvZ
	ofVec2f pos = getPosition();
	float dist = pos.distance(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2));
	//‹——£‚É‚æ‚Á‚Ä‰¹—ÊŒvZ
	amp = (1.0 - dist / 400.0)*0.2;
	if (amp < 0) {
		amp = 0;
	}
	mySound.setVolume(amp); //‰¹—Êİ’è
}