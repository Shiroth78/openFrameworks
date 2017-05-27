#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofEnableSmoothing();
	ofEnableBlendMode(OF_BLENDMODE_ADD); //��ʍ��F�����Z����
	myImage.loadImage("sample.PNG");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	myImage.draw(20, 20); //�`��
	unsigned char *pixels = myImage.getPixels().getData(); //�摜�f�[�^��z��Ɋi�[
	/*0.8.4�܂ł� getPixels() �� unsigned char * (���̃s�N�Z���z��)��Ԃ��Ă�����
	�ȍ~�� ofPixels & ��Ԃ����߁A���l�̋����������邽�߂ɂ�getPixels().getData() �Ƃ���*/
	int w = myImage.getWidth();
	int h = myImage.getHeight();
	for (int i = 0;i < w;i += 8) {
		for (int j = 0;j < h;j += 8) {
			//RGB�f�[�^�擾
			int valueR = pixels[j * 3 * w + i * 3];
			int valueG = pixels[j * 3 * w + i * 3 + 1];
			int valueB = pixels[j * 3 * w + i * 3 + 2];
			ofSetColor(255, 0, 0, 63);
			ofCircle(440 + i, 20 + j, 10 * valueR / 255.0);
			ofSetColor(0, 255, 0, 63);
			ofCircle(440 + i, 20 + j, 10 * valueG / 255.0);
			ofSetColor(0, 0, 255, 63);
			ofCircle(440 + i, 20 + j, 10 * valueB / 255.0);
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		grabbedImage.grabScreen(430, 10, 420, 642);
		grabbedImage.saveImage("grabbedImage.png");
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
