#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	georgia.loadFont("sample.ttf", 60); //font読み込み
	fontX = ofGetWidth(); // fontのX軸上表示位置初期化

}

//--------------------------------------------------------------
void ofApp::update(){ 
	fontX -= 1; //フォントを左に移動
	ofRectangle rect = georgia.getStringBoundingBox("Hello world!", 0, 0); // フォントを囲む長方形計算
	if (fontX < -rect.width) {
		fontX = ofGetWidth(); //左がはみ出たら右端に戻す
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
