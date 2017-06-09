#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);

	vidGrabber.initGrabber(320, 240); //�r�f�I��荞�ݏ�����
	colorImg.allocate(320, 240); //OpenCV��͗p�J���[�摜�̈�m��
	grayImg.allocate(320, 240); //�O���[�X�P�[���p
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);
	
	bLearnBakground = true;
	threshold = 100;

}

//--------------------------------------------------------------
void ofApp::update(){
	bool bNewFrame = false;
	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();
	if (bNewFrame) {
		//colorImg.setFromPixels(vidGrabber.getPixels(), 320, 240);
		colorImg.setFromPixels(vidGrabber.getPixels());
		grayImg = colorImg;
		//�V�K�ɔw�i�L�^
		if (bLearnBakground == true) {
			grayBg = grayImg;
			bLearnBakground = false;
		}
		grayDiff.absDiff(grayBg, grayImg); //������Βl�擾
		grayDiff.threshold(threshold); //臒l�œ�l��
		contourFinder.findContours(grayDiff, 20, (340 * 260) / 3, 10, true); //�֊s���ofinderContours(�摜�A�ŏ��G���A�A�ő�G���A�A���̐��A�������o���邩�j
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	colorImg.draw(10, 10);
	grayImg.draw(340, 10);
	grayBg.draw(10, 260);
	grayDiff.draw(340, 260);
	contourFinder.draw(340, 500);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		bLearnBakground = true;
		break;
	case '+':
		threshold++;
		if (threshold > 255) threshold = 255;
		break;
	case '-':
		threshold--;
		if (threshold < 0) threshold = 0;
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
