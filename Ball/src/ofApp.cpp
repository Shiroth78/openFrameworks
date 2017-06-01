#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofSetCircleResolution(32);
	ofEnableAlphaBlending();
	ofSetFrameRate(30);

	/*
	myBall.setPos(ofPoint(300., 300.));
	myBall.setRadius(100);
	myBall.setSpeed(ofPoint(3., 5.));
	*/

}

//--------------------------------------------------------------
void ofApp::update(){
	//myBall.update();
	for (int i = 0; i < balls.size();i++) {
		balls[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	//myBall.draw();
	for (int i = 0; i < balls.size();i++) {
		balls[i].draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
	case'f':
		ofToggleFullscreen(); //フルスクリーン表示
		break;
	case 'r':
		balls.clear();
		break;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	int bsize = balls.size();

	if (bsize < 1) {
		//新しいボールの生成
		Ball b = Ball();
		b.setPos(ofPoint(mouseX, mouseY));
		b.setRadius(ofGetHeight() / 3);
		b.setSpeed(ofPoint(0, 0));
		balls.push_back(b);
	}
	
	//クリックした円を4つに分裂
	for (int i = 0;i < bsize;i++) {
		ofPoint pos = balls[i].getPos();
		float radius = balls[i].getRadius();
		float dist = ofDist(pos.x, pos.y, mouseX, mouseY); //distance
		if (dist < radius) {
			//元の円を左に、上下右は新しく生成
			balls[i].setRadius(radius*0.6);
			balls[i].setPos(ofPoint(pos.x - radius*0.7, pos.y));
			balls[i].setSpeed(ofPoint(ofRandom(-radius / 150, radius / 150), ofRandom(-radius / 150, radius / 150)));

			Ball b1 = Ball();
			b1.setRadius(radius*0.6);
			b1.setPos(ofPoint(pos.x + radius*0.7, pos.y));
			b1.setSpeed(ofPoint(ofRandom(-radius / 150, radius / 150), ofRandom(-radius / 150, radius / 150)));
			balls.push_back(b1);

			Ball b2 = Ball();
			b2.setRadius(radius*0.6);
			b2.setPos(ofPoint(pos.x, pos.y - radius*0.7));
			b2.setSpeed(ofPoint(ofRandom(-radius / 150, radius / 150), ofRandom(-radius / 150, radius / 150)));
			balls.push_back(b2);

			Ball b3 = Ball();
			b3.setRadius(radius*0.6);
			b3.setPos(ofPoint(pos.x, pos.y + radius*0.7));
			b3.setSpeed(ofPoint(ofRandom(-radius / 150, radius / 150), ofRandom(-radius / 150, radius / 150)));
			balls.push_back(b3);
		}
	}

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
