#pragma once
#include "ofMain.h"

class Ball
{
private:
	ofPoint pos; //‰~‚ÌˆÊ’u
	float radius; //‰~‚Ì”¼Œa
	ofPoint speed; //‰~‚Ì‘¬“x
	float phase; //‰~‚ÌLkˆÊ‘Š
	float phaseSpeed; //‰~‚ÌLk‘¬“x
	float strechedRadius; //LkŒã”¼Œa

public:
	Ball(); // ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	void draw();
	void update();
	void setRadius(float radius); //radiusƒZƒbƒ^[
	float getRadius(); //radiusƒQƒbƒ^[
	void setPos(ofPoint pos); //posƒZƒbƒ^[
	ofPoint getPos(); //posƒQƒbƒ^[
	void setSpeed(ofPoint speed); //speed setter
	ofPoint getSpeed(); // speed getter
};

