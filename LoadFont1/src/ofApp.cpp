#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	georgia.loadFont("sample.ttf", 60); //font�ǂݍ���
	fontX = ofGetWidth(); // font��X����\���ʒu������

}

//--------------------------------------------------------------
void ofApp::update(){ 
	fontX -= 1; //�t�H���g�����Ɉړ�
	ofRectangle rect = georgia.getStringBoundingBox("Hello world!", 0, 0); // �t�H���g���͂ޒ����`�v�Z
	if (fontX < -rect.width) {
		fontX = ofGetWidth(); //�����͂ݏo����E�[�ɖ߂�
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0, 127, 255);
	georgia.drawString("Hello world!", fontX, ofGetHeight() / 2);

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
