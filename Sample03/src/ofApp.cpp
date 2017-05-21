#include "ofApp.h"

static const int NUM = 1000;
float loc_x[NUM], loc_y[NUM], radius[NUM];
float speed_x[NUM], speed_y[NUM];
int red[NUM], green[NUM], blue[NUM];

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	ofSetCircleResolution(64);
	ofEnableAlphaBlending();

	for (int i = 0;i < NUM;i++) {
		loc_x[i] = ofRandom(0, ofGetWidth());
		loc_y[i] = ofRandom(0, ofGetHeight());
		speed_x[i] = ofRandom(-5, 5);
		speed_y[i] = ofRandom(-5, 5);
		radius[i] = ofRandom(4, 40);
		red[i] = ofRandom(0, 255);
		green[i] = ofRandom(0, 255);
		blue[i] = ofRandom(0, 255);
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0;i < NUM;i++) {
		loc_x[i] += speed_x[i];
		loc_y[i] += speed_y[i];

		if (loc_x[i] < 0 || loc_x[i] > ofGetWidth()) {
			speed_x[i] = speed_x[i] * -1;
		}
		if (loc_y[i] < 0 || loc_y[i] > ofGetHeight()) {
			speed_y[i] = speed_y[i] * -1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0;i < NUM;i++) {
		ofSetColor(red[i], green[i], blue[i], 127);
		ofCircle(loc_x[i], loc_y[i], radius[i]);
	}
	/*
	if (loc_x < 0) {
	loc_x = ofGetWidth();
	}
	if (loc_x > ofGetWidth()) {
	loc_x = 0;
	}
	if (loc_y < 0) {
	loc_y = ofGetHeight();
	}
	if (loc_y > ofGetHeight()) {
	loc_y = 0;
	}
	*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
