#include "ofApp.h"

float x[1000];
float y[1000];
float radius[1000];
int red[1000];
int green[1000];
int blue[1000];

//--------------------------------------------------------------
void ofApp::setup() {
	int i;
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	ofSetCircleResolution(64);
	for (i = 0;i < 1000;i++) {
		x[i] = ofRandom(0, ofGetWidth());
		y[i] = ofRandom(0, ofGetHeight());
		radius[i] = ofRandom(10, 40);
		red[i] = ofRandom(0, 255);
		green[i] = ofRandom(0, 255);
		blue[i] = ofRandom(0, 255);
	}

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	int i;
	for (i = 0;i < 1000;i++) {
		ofSetColor(red[i], green[i], blue[i], 63);
		ofCircle(x[i], y[i], radius[i]);
	}

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
