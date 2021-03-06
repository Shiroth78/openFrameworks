#pragma once
#include "ofMain.h"

class Ball
{
private:
	ofPoint pos; //~ΜΚu
	float radius; //~ΜΌa
	ofPoint speed; //~Μ¬x
	float phase; //~ΜLkΚ
	float phaseSpeed; //~ΜLk¬x
	float strechedRadius; //LkγΌa

public:
	Ball(); // RXgN^
	void draw();
	void update();
	void setRadius(float radius); //radiusZb^[
	float getRadius(); //radiusQb^[
	void setPos(ofPoint pos); //posZb^[
	ofPoint getPos(); //posQb^[
	void setSpeed(ofPoint speed); //speed setter
	ofPoint getSpeed(); // speed getter
};

