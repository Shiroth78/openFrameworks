#include "CustomCircle.h"

void CustomCircle::draw() {
	float radius = getRadius();
	ofPushMatrix(); //À•W•ÏX
	ofTranslate(getPosition().x, getPosition().y);
	ofFill(); //“h‚è‚Â‚Ô‚µ
	ofSetColor(31, 127, 255, 100);
	ofCircle(0, 0, radius);
	ofSetColor(31, 127, 255, 200);
	ofCircle(0, 0, radius*0.7);
	ofPopMatrix(); //À•W‚ğŒ³‚É–ß‚·
}