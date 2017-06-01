#include "Ball.h"

Ball::Ball() {
	pos = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	//pos = ofPoint(400., 300.);
	radius = 100.0;
	speed = ofPoint(0., 0.);
	phaseSpeed = ofRandom(0.1, 0.5);
	phase = 0;
}

void Ball::draw() {
	ofSetColor(31, 63, 255);
	ofCircle(pos.x, pos.y, strechedRadius);

	ofSetColor(255, 0, 0, 200);
	ofCircle(pos.x, pos.y, radius / 10.0);
	ofSetColor(31, 63, 255);
}

void Ball::update() {
	//circle stretch
	strechedRadius = radius + sin(phase)*radius/4;
	phase += phaseSpeed;
	if (phase > TWO_PI) {
		phase -= TWO_PI;
	}

	//circle reflection
	pos += speed;
	if (pos.x < radius || pos.x > ofGetWidth() - radius) {
		speed.x *= -1.;
	}
	if (pos.y < radius || pos.y > ofGetHeight() - radius) {
		speed.y *= -1.;
	}
}

//pos setter
void Ball::setPos(ofPoint _pos) {
	pos = _pos;
}

//pos getter
ofPoint Ball::getPos() {
	return pos;
}

//radius setter
void Ball::setRadius(float _radius) {
	radius = _radius;
}

//radius getter
float Ball::getRadius() {
	return radius;
}

//speed setter
void Ball::setSpeed(ofPoint _speed) {
	speed = _speed;
}

//speed getter 
ofPoint Ball::getSpeed() {
	return speed;
}