#include "ofApp.h"
#include "stdio.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofEnableSmoothing();
	//ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	sampleMovie.loadMovie("sample.mp4"); //mp4がダメたときはK-Liteコーデックをインスコ
	//sampleMovie.load("sample.mp4");
	sampleMovie.play();

}

//--------------------------------------------------------------
void ofApp::update(){
	sampleMovie.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(127,127,127);
	sampleMovie.draw(20, 20);
	unsigned char *pixels = sampleMovie.getPixels().getData();
	for (int i = 0;i < sampleMovie.getWidth();i += 8) {
		for (int j = 0;j < sampleMovie.getHeight();j += 8) {
			unsigned char r = pixels[(j * 320 + i) * 3];
			unsigned char g = pixels[(j * 320 + i) * 3 + 1];
			unsigned char b = pixels[(j * 320 + i) * 3 + 2];
			ofSetColor(255, 0, 0, 100);
			ofCircle(720 + i, 20 + j, 10.0*(float)r / 255.0);
			ofSetColor(0, 255, 0, 100);
			ofCircle(720 + i, 20 + j, 10.0*(float)g / 255.0);
			ofSetColor(0, 0, 255, 100);
			ofCircle(720 + i, 20 + j, 10.0*(float)b / 255.0);
		}
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case '0':
		sampleMovie.firstFrame();
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	sampleMovie.setPosition((float)x / (float)ofGetWidth());

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	sampleMovie.setPaused(true);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	sampleMovie.setPaused(false);

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
