#include "CustomLetter.h"

CustomLetter::CustomLetter() {
	r = ofRandom(0, 255);
	g = ofRandom(0, 255);
	b = ofRandom(0, 255);
	
}

void CustomLetter::update() {

}

void CustomLetter::draw() {
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y);
	ofFill();
	ofSetColor(r, g, b, 100);
	//ofRectangle rect = font.getStringBoundingBox(&letter, 0, 0);
	//w = rect.width*scale;
	//h = rect.height*scale;
	font.drawString(&letter, 0, 0);
	ofPopMatrix();
}
