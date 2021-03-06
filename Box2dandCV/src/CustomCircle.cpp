#include "CustomCircle.h"

void CustomCircle::draw() {
	float radius = getRadius();
	ofPushMatrix(); //座標変更
	ofTranslate(getPosition().x, getPosition().y);
	ofFill(); //塗りつぶし
	ofSetColor(31, 127, 255, 100);
	ofCircle(0, 0, radius);
	ofSetColor(31, 127, 255, 200);
	ofCircle(0, 0, radius*0.7);
	ofPopMatrix(); //座標を元に戻す
}