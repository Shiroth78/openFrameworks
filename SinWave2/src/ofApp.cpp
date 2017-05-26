#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bufSize = 256;
	ofBackground(0, 0, 0);
	ofSetColor(0, 0, 255);
	ofSoundStreamSetup(0, 2);
	left = new float[bufSize];
	right = new float[bufSize];

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float audioHeight = ofGetHeight() / 2.0f;
	float phaseDiff = ofGetWidth() / float(bufSize); //ˆÊ‘Š

	ofSetColor(0, 0, 255);
	ofNoFill();
	ofSetLineWidth(2);

	ofBeginShape();
	for (int i = 0;i < bufSize;i++) {
		ofVertex(i*phaseDiff, audioHeight / 2 + left[i] * audioHeight);//ofVertex()‚©‚çŽŸ‚ÌofVertex()‚ð‚Â‚È‚®
	}
	ofEndShape();

	ofBeginShape();
	for (int i = 0;i < bufSize;i++) {
		ofVertex(i*phaseDiff, audioHeight / 2 * 3 + right[i] * audioHeight);
	}
	ofEndShape();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

void ofApp::audioReceived(float * input, int bufferSize, int nChannels) {
	for (int i = 0;i < bufferSize;i++) {
		left[i] = input[i * 2];
		right[i] = input[i * 2 + 1];
	}

}